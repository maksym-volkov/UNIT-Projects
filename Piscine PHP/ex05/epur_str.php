#!/usr/bin/php
<?php
	$str = $argv[1];
	$i = 0;
	$l = 0;
	while ($str[$i])
	{
		while ($str[$i] == " " && $str[$i])
			$i++;
		if ($l > 0 && $str[$i])
			echo " ";
		$l++;
		while ($str[$i] != " " && $str[$i])
			echo $str[$i++];

	}
	echo "\n";
?>
