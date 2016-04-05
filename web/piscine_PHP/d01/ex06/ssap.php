#!/usr/bin/php
<?PHP
	if ($argc < 2)
	{
		exit ;
	}
	$tab = array();
	$i = 0;
	while (++$i < $argc)
	{
		if (empty($argv[$i]))
			continue ;
		if (ctype_space($argv[$i]) == TRUE)
			continue ;
		$tab = array_merge($tab, explode(" ", $argv[$i]));
	}
	if ($tab == NULL)
	{
		exit ;
	}
	sort($tab, SORT_STRING);
	foreach ($tab as $content)
	{
		if (empty($content))
			continue ;
		echo "$content\n";
	}
?>
