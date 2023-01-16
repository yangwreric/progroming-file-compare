@echo off 
:loop
	rnd.exe %random%>in.in
	std.exe<in.in>std.out
	test.exe<in.in>test.out
	fc std.out test.out
	if errorlevel 0 goto loop
	pause
goto loop