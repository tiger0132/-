@echo off
if "%1"=="" goto loop
copy %1 circle.in >nul
echo Data %2
time<nul
circle.exe
time<nul
fc circle.out %1.out
del circle.in
del circle.out
pause
goto end
:loop
set /a n=1
for %%i in (ber ade xxx ooo xxz zzm) do (
	call %0 %%i %n%
	set /a n+=1
)
:end