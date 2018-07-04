#!/usr/bin/php
<?php
while(1)
{
	echo "Enter a number: ";
	$line = trim(fgets(STDIN));
	if (feof(STDIN) == TRUE)
		exit();
	if (!is_numeric($line))
	{
		echo "'$line' is not a number";
		echo "\n";
	}
	else
	{
		echo "The number $line is ";
		if (substr($line, -1) % 2 == 0)
			echo "even\n";
		else
			echo "odd\n";
	}
}
?>
