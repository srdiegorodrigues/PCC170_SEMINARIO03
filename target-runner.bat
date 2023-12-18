::##############################################################################
:: This script is the command that is executed every run.
:: Check the examples in examples/
::
:: This script is run in the execution directory (execDir, --exec-dir).
::
:: PARAMETERS:
:: %1 is the candidate configuration number
:: %2 is the instance ID
:: %3 is the seed
:: %4 is the instance name
:: The rest (%* after `shift 4') are parameters to the run
::
:: RETURN VALUE:
:: This script should print one numerical value: the cost that must be minimized.
:: Exit with 0 if no error, with 1 in case of error
::##############################################################################

@echo off

:: Please change the path to the correct one
SET "exe= source\main.exe"
SET "fixed_params= "

SET candidate=%1
SHIFT
SET instance_id=%1
SHIFT
SET seed=%1
SHIFT
SET instance=%1
SHIFT

SET candidate_parameters=%*

SET "stdout=c%candidate%-%instance_id%.stdout"
SET "stderr=c%candidate%-%instance_id%.stderr"

::if not exist %exe% error "%exe%: not found or not executable (pwd: %(pwd))"

:: If the program just prints a number, we can use 'exec' to avoid
:: creating another process, but there can be no other commands after exec.
::exec %exe %FIXED_PARAMS% -i %instance %candidate_parameters%
:: exit 1
:: 
:: Otherwise, save the output to a file, and parse the result from it.
:: (If you wish to ignore segmentation faults you can use '{}' around
:: the command.)
%exe% %FIXED_PARAMS% %instance% %candidate_parameters%

::if %errorlevel% neq 0 exit /b %errorlevel%

:: # This may be used to introduce a delay if there are filesystem
:: # issues.
:: SLEEPTIME=1
:: while [ ! -s "%stdout%" ]; do
::     sleep %SLEEPTIME
::     let "SLEEPTIME += 1"
:: done
::
:: This is an example of reading a number from the output.
:: It assumes that the objective value is the first number in
:: the first column of the last line of the output.

::if exist %stdout% (

	setlocal EnableDelayedExpansion
	set "cmd=findstr /R /N "^^" %stdout% | find /C ":""

	echo %cmd%

	::del %stdout% %stderr%
	
	exit 0
	
::) ELSE (

	::exit /b
::)
