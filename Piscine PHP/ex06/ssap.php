#!/usr/bin/php
<?php
	function ft_split($str)
	{
		$r = explode(" ", $str);
		sort($r);
		$ret = array();
		foreach ($r as $key)
		{
			if (!empty($key))
				$ret[] = $key;
		}
		unset($r);
		return ($ret);
	}
	$res = array();
	for ($i = 1; $i < $argc; $i++)
	{
		$ret = ft_split($argv[$i]);
		$res = array_merge($res, $ret);
	}
	sort($res);
	foreach ($res as $elem) {
		echo $elem."\n";
	}
?>