@echo off
setlocal enabledelayedexpansion

set /a graczP=0
set /a przeciwnikP=0

set graczSkonczyl=False
set przeciwnikSkonczyl=False

:: %1 - min, %2 - max, %3 - output
:GetRandom
  set /a "%3=!random! %% (%2 - %1 + 1) + %1"
exit /b 0

:LosujKarty
  call :GetRandom 1 13 karta
exit /b 0