#!/usr/bin/env pike

//        legal.pike - Count the number of legal go boards.
//        Copyright 2005 by Gunnar Farnebäck
//        gunnar@lysator.liu.se
//
//        You are free to do whatever you want with this code.
//
//
// This program computes the number of legal go board configurations
// for a rectangular board of a given size. It is efficient enough to
// handle boards up to 8x8 within minutes and up to 11x11 in less than
// 24 hours (on a fast computer). For rectangular boards MxN, large N
// can be handled efficiently as long as M is kept small.
//
// The program is inspired by the Computer Go List postings of Jeffrey
// Rainy,
//
//   Is there any published articles or websites stating the exact number of
//   legal goban configurations that are possible for a given goban size ?
//   
//   The best I found, from Sensei's Library is :
//   
//   1x1: 1 legal, 2 illegal, prob 0.333333
//   2x2: 57 legal, 24 illegal, prob 0.703704
//   3x3: 12675 legal, 7008 illegal, prob 0.643957
//   4x4: 24318165 legal, 18728556 illegal, prob 0.564925
//   4x5: 1840058693 legal, 1646725708 illegal, prob 0.527724
//   
//   I realise this is of no interest except from a purely
//   theoretical/combinatorial viewpoint. However, I think I could come up with
//   the exact values up to at least 9x9. Was this done before ? Would anyone
//   find it useful or at least somehow interesting ?
//
// and the response from Eric Boesch,
//
//   >Would anyone find it useful or at least somehow interesting ?
//
//   Yes, I think the answer would be interesting, and the method used to
//   arrive at numbers for such large boards would be even more
//   interesting. At first I thought you were crazy to think the
//   computation was practical for 9x9, but after considerable thought, I'm
//   not so sure. I think I've finally worked out an angle. In any case, it
//   sounds like not only did you find an angle first, but you also had the
//   insight to realize an answer might be possible in the first place,
//   which I did not. Considering where you say Sensei's left off (5x4), I
//   bet they used brute force, which isn't very interesting.
//   
//   Here are my thoughts on the problem. I have not actually worked out
//   the solution -- I figure you have dibs on this problem anyway :)
//   Possible spoiler?
//   
//   Bisection and divide-and-conquer, while (I think) straightforward
//   enough for 1-dimensional boards, seemed very difficult to do for
//   2-dimensional ones. Hmm...
//   
//   Instead of divide-and-conquer, I think you should work out from the
//   corner, adding stones one at a time, column by column, keeping an
//   array mapping all possible border states to the number of different
//   overall region states that share that same border state. The border is
//   the set of intersections that are inside the region that are adjacent
//   to intersections outside the region. The border state is not only the
//   color of the border intersections, but also whether those stones
//   already have liberties, or whether they need to connect to outside
//   liberties, and also whether those stones are connected to each other.
//   For example:
//   
//   -----
//   | #
//   | # O
//   | # #
//   | # O
//   | O .
//   -----
//   
//   If this is our region, then the border consists of the four rightmost
//   intersections (the rightmost ones in each row). The border colors are
//   #,O,#,O, and "." (empty), but the border state is more than just the
//   colors of the border stones. It's also important to know that the
//   topmost O stone needs to connect (directly or indirectly) to an
//   outside liberty. The two # stones on the border also need to connect
//   to a liberty, but since they are already connected to each other, a
//   single liberty at either end suffices.
//   
//   So the number of possible border configurations is strictly greater
//   than 3^(# of border intersections). I have no idea what the exact
//   number would be, but as long as the effective exponent base isn't too
//   big, the space demands for 9x9 should be manageable. For example, 4^9
//   is just a quarter million.
//   
//   In sum, when you're adding a new intersection to the region, you
//   iterate through all of the old border states, and through all of the
//   possible colors for that new intersection (black, white, empty). For
//   each old border state, you compute the new border state that results
//   from adding the given stone to the old border, and you add the number
//   of positions having the old border state to the number of positions
//   having the new border state. Once you have added all 81 stones, the
//   single (null) border state number will equal the total number of valid
//   positions -- make sure to use either floating point or bignums.
//
// For the full postings, see
// http://computer-go.org/pipermail/computer-go/2005-January/002387.html
// http://computer-go.org/pipermail/computer-go/2005-January/002412.html
//
//
// This program implements the algorithm as outlined by Eric.
// It is written in Pike. See http://pike.ida.liu.se for documentation
// and download. It should be noted that the "int" type in Pike
// automatically switches to bignums when the values become too large
// for the native integers on the platform.
//
// The internal representation of the border state is a string with a
// length equaling the height of the board and containing the
// following characters:
//
// X: A black stone with at least one liberty guaranteed.
// O: A white stone with at least one liberty guaranteed.
// .: An empty vertex.
// |: An edge vertex, only used initially while traversing the first column.
// a,b,c, etc.: White strings with no liberty found so far.
// A,B,C, etc.: Black strings with no liberty found so far.
//
// For strings without liberties the rule is that connected stones
// have the same letter and disconnected stones have different
// letters. Furthermore the state is normalized so that the first
// occurence of "a" always precedes the first occurence of "b", etc.,
// and so that there are no holes in the letter sequences. This
// normalization is not required for the program to give correct
// results (*) but improves the performance by keeping the set of
// border states as small as possible.
//
// There is clearly no need to keep track of connectivity for stones
// with liberties.
//
// The state is recorded from the bottom and up. The position in
// Eric's example above is represented by the state string ".OAaA".
//
// During the computation of new state the state string is converted
// into an array of single-character strings. This is because strings
// are immutable in Pike but arrays can be destructively modified.
//
// (*) Not quite true since one piece of the code would need to be
//     modified in this case, as documented in the code comments.
//
//
// Results for quadratic boards computed by this program:
//
// 1x1   1
// 2x2   57
// 3x3   12675
// 4x4   24318165
// 5x5   414295148741
// 6x6   62567386502084877
// 7x7   83677847847984287628595
// 8x8   990966953618170260281935463385
// 9x9   103919148791293834318983090438798793469
// 10x10 96498428501909654589630887978835098088148177857
//
// The time complexity seems to increase roughly by 7^N which means
// that 11x11 should be solvable in about 24 hours, 12x12 in a week,
// and 13x13 in less than two months. Please report the results if you
// find the computer time to do this.

/**********************************************************/

// Normalize the state array so that the first occurences of strings
// in "state" that are included in "strings" are ordered and without
// holes. If called succesively with black_strings and white_strings
// the state will be normalized as described above.
array(string) normalize_state(array(string) state, array(string) strings)
{
  int j = 0;
  for (int i = 0; i < sizeof(state); i++) {
    if (has_value(strings, state[i])) {
      if (state[i] > strings[j]) {
	// Out of order or a hole in the sequence. Exchange
	// this letter with the next letter in turn. Use "@"
	// as a temporary placeholder.
	string x = state[i];
	state = replace(state, strings[j], "@");
	state = replace(state, x, strings[j]);
	state = replace(state, "@", x);
	j++;
      }
      else if (state[i] == strings[j])
	j++;
    }
  }
  return state;
}


// Count the number of legal boards of the given size.
int count_legal_boards(int height, int width)
{
  // The border state count is represented by a mapping which
  // associates each border state string with the number of
  // configurations of the stones placed on the board so far having
  // that border state.
  mapping(string:int) new_state_count = ([]);
  mapping(string:int) old_state_count = ([]);
  
  // Letters used for strings without liberties. There can be at
  // most height/2 strings of each color in the border state but we
  // need one extra letter to avoid indexing out of range in
  // normalize_state().
  //
  // The division by "" (the empty string) splits the string into an
  // array of one-character strings.
  //
  // Naturally "O" and "X" are excluded here. If someone in the far
  // future finds a computer capable of handling heights larger than
  // 44 fast enough to be useful, these lists need to be extended. Any
  // characters can be used in arbitrary order as long as there are no
  // collisions.
  array(string) white_strings = "abcdefghijklmnpqrstuvwyz"[0..height/2+1] / "";
  array(string) black_strings = "ABCDEFGHIJKLMNPQRSTUVWYZ"[0..height/2+1] / "";
  
  // The initial state is "|" repeated height times, e.g. "|||||"
  // for 5xN boards.
  string edge = "|" * height;
  new_state_count[edge] = 1;
  
  // Keep track of the maximum number of border states for statistics.
  int max_number_of_border_states = 0;
  
  // Traverse the board in the order new vertices are added. The outer
  // loop goes from the left to the right and the inner loop from the
  // bottom to the top.
  for (int j = 0; j < width; j++)
    for (int i = 0; i < height; i++) {
      // Move the previous new state count to old_state_count and
      // start over with an empty new_state_count.
      old_state_count = new_state_count;
      new_state_count = ([]);

      // Loop over the previous states.
      foreach (indices(old_state_count), string state)
	// Add an empty vertex, a black stone, and a white stone in turn.
	foreach (({"empty", "black", "white"}), string new_stone) {
	  // Convert the state string to a state array.
	  array(string) new_state = state / "";

	  // What matters in the computation of the new state is what
	  // we have to the left and below. If we are at the bottom of
	  // the column the neighbor below is the edge symbol "|".
	  string left = new_state[i];
	  string down = (i == 0) ? "|" : new_state[i-1];

	  // Of particular interest is whether we have a string
	  // without liberties of one of the colors to the left or
	  // below.
	  int black_string_left = has_value(black_strings, left);
	  int black_string_down = has_value(black_strings, down);
	  int white_string_left = has_value(white_strings, left);
	  int white_string_down = has_value(white_strings, down);

	  // If we find that the new configuration is illegal we set
	  // this variable to 1 to mark that it should be discarded.
	  int bad_state = 0;

	  // Handle each addition case by case.
	  switch (new_stone) {
	  case "empty":
	    // When we add an empty vertex, the configuration is
	    // guaranteed to be valid and the new state at the current
	    // position will definitely be ".". If we have a string
	    // without liberties to the left or below it has now
	    // received a liberty and its stones should be converted
	    // either to "X" or "O".
	    new_state[i] = ".";
	    if (black_string_left)
	      new_state = replace(new_state, left, "X");
	    if (black_string_down)
	      new_state = replace(new_state, down, "X");
	    if (white_string_left)
	      new_state = replace(new_state, left, "O");
	    if (white_string_down)
	      new_state = replace(new_state, down, "O");
	    break;
	    
	  case "black":
	    // If we have a white string without liberties to the left
	    // and this was its last stone on the border, it can no
	    // longer get any liberty and thus the configuration is
	    // illegal.
	    if (white_string_left && sizeof(state - left) == height - 1) {
	      bad_state = 1;
	      break;
	    }

	    // If we have at least one empty vertex or a black stone
	    // with liberty to the left or to the right, the new stone
	    // will also have at least one liberty.
	    if (has_value("X.", left) || has_value("X.", down)) {
	      new_state[i] = "X";
	      // Furthermore, if the other neighbor was a black string
	      // without liberties, it has also received a liberty
	      // now.
	      if (black_string_left)
		new_state = replace(new_state, left, "X");
	      else if (black_string_down)
		new_state = replace(new_state, down, "X");
	    }
	    else if (black_string_left && black_string_down) {
	      // Both neighbors are black strings without liberties.
	      // These need to be merged and the new string will also
	      // lack liberties. There is no need to set the state at
	      // the current position explicitly as it will be part of
	      // the string inherited from the left.
	      if (left != down)
		new_state = replace(new_state, down, left);
	    }
	    else if (black_string_down) {
	      // Black string without liberties below and a white
	      // stone (with or without liberties) or the edge to the
	      // left. Extend the string below to the current
	      // position.
	      new_state[i] = down;
	    }
	    else if (!black_string_left) {
	      // If we have a black string without liberties to the
	      // left and a white stone or the edge below we do not
	      // need to do anything as the border state remains
	      // unchanged by adding the new stone to the string to
	      // the left.
	      //
	      // If we have white stones or edges both to the left and
	      // below we get a new string without liberties now. We
	      // temporarily use the last available string letter,
	      // which is guaranteed to be free and let the state
	      // normalization change it to the appropriate letter.
	      // (However, if state normalization were to be turned
	      // off it would be necessary to search for a free string
	      // letter here.)
	      new_state[i] = black_strings[-1];
	    }
	    break;
	    
	  case "white":
	    // This code is identical to the "black" case above but
	    // with reversed roles for black and white. We do not
	    // repeat the comments above.
	    if (black_string_left && sizeof(state - left) == height - 1) {
	      bad_state = 1;
	      break;
	    }
	    
	    if (has_value("O.", left) || has_value("O.", down)) {
	      new_state[i] = "O";
	      if (white_string_left)
		new_state = replace(new_state, left, "O");
	      else if (white_string_down)
		new_state = replace(new_state, down, "O");
	    }
	    else if (white_string_left && white_string_down) {
	      if (left != down)
		new_state = replace(new_state, down, left);
	    }
	    else if (white_string_down)
	      new_state[i] = down;
	    else if (!white_string_left)
	      new_state[i] = white_strings[-1];
	    break;
	  }

	  // Throw away bad configurations. Normalize good ones and
	  // then add them to the state count.
	  if (!bad_state) {
	    new_state = normalize_state(new_state, black_strings);
	    new_state = normalize_state(new_state, white_strings);
	    new_state_count[new_state * ""] += old_state_count[state];
	  }
	}

      // Update statistics.
      if (sizeof(new_state_count) > max_number_of_border_states)
	max_number_of_border_states = sizeof(new_state_count);
    }

  // The board has been traversed. The final border states which
  // include black or white strings without liberties correspond to
  // illegal board configurations and must be excluded. We do this by
  // summing the state counts for state strings only containing the
  // characters ".", "X", and "O".
  int sum = 0;
  foreach (indices(new_state_count), string state) {
    if (sizeof(state - "." - "X" - "O") == 0)
      sum += new_state_count[state];
  }

  // Print statistics.
  printf("Max number of border states: %d\n",
	max_number_of_border_states);
  
  return sum;
}


int main(int argc, array(string) argv)
{
  if (argc < 3) {
    werror("Usage: pike legal.pike height width\n");
    exit(1);
  }
  
  int height = (int) argv[1];
  int width = (int) argv[2];
  
  int num_legal = count_legal_boards(height, width);

  // If the board is too large, we cannot convert to float before the
  // division to compute the fraction of legal boards since that would
  // cause overflow. With this trick we use bignum integers in the
  // division and get a result that is safe to convert to float.
  printf("%dx%d: %d (%2.4f%%) legal boards\n", height, width, num_legal,
	0.000001 * (100000000 * num_legal / pow(3, height*width)));

  // Signal successful execution.
  return 0;
}