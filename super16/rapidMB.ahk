#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

pausS	:=	50
pausL	:=	50

F13::
Sleep pausS
;	this is to give enough time for the key to be released
Loop
{
	Click
	Sleep pausL
}	Until GetKeyState("F13", p)
return

F14::
Sleep pausS
;	this is to give enough time for the key to be released
Loop
{
	Click, right
	Sleep pausL
}	Until GetKeyState("F14", p)

return

F17::ExitApp
;	terminates the script, in case something goes wrong