#!/usr/bin/php
<?php
function ft_split($str)
{
	$r = explode(" ", $str);
	$ret = array();
	foreach ($r as $key)
	{
		if (!empty($key))
			$ret[] = $key;
	}
	unset($r);
	return ($ret);
}
$str = $argv[1];
$ret = ft_split($str);
$string = "";
$len = count($ret);
for ($i = 1; $i < $len; $i++)
	$string = $string.$ret[$i]." ";
$string = $string.$ret[0]."\n";
echo $string;
?>