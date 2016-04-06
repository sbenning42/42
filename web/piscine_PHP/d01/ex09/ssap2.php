#!/usr/bin/php
<?PHP
	if ($argc < 2)
	{
		exit ;
	}
	#$argvv = array("php", "toto", "tutu", "4234", "_hop XXX", "##", "1948372 AhAhAh");
	$argvv = array("", "toto", "tutu", "", "_hop XXX", "             ##", "1948372                 AhAhAh", "                   ");
	$tab = array();
	$i = 0;
	foreach ($argvv as $arg)
	{
		if ($i == 0 OR empty($arg) == TRUE)
		{
			$i = 1;
			continue ;
		}
		$tab = array_merge($tab, explode(" ", $arg));	
	}
	foreach ($tab as $content)
	{
		if (empty($content) == TRUE)
		{
			continue ;
		}
		else if (ctype_alpha($content))
		{
			$alpha[] = $content;
		}
		else if (ctype_digit($content))
		{
			$digit[] = $content;
		}
		else
		{
			$other[] = $content;
		}
	}
	sort($alpha, SORT_STRING | SORT_FLAG_CASE);
	sort($digit, SORT_STRING);
	sort($other, SORT_STRING);
	foreach ($alpha as $content)
	{
		echo "$content\n";
	}
	foreach ($digit as $content)
	{
		echo "$content\n";
	}
	foreach ($other as $content)
	{
		echo "$content\n";
	}
?>
