#!/usr/bin/php
<?PHP
	if ($argc < 2)
	{
		exit ;
	}
	$word = explode(" ", $argv[1]);
	$rot = -1;
	$index = 0;
	foreach ($word as $content)
	{
		$index++;
		if (empty($content) == TRUE)
		{
			continue ;
		}
		if ($rot == -1)
		{
			$rot = $index - 1;
			continue ;
		}
		echo "$content ";
	}
	if ($rot != -1)
	{
		echo "$word[$rot]\n";
	}
?>
