@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy predict%1.in std.in >nul
std
copy std.out predict%1.out
pause
del std.in
goto end
:loop
  for %%i in (0 1 2 3 4) do call %0 %%i
:end