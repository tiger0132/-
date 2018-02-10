template <int T>
class C {
	enum {
		f = C<T-1>::f;
	};
};

int main() {
	C<0>::f;
}
