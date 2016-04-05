#!/usr/bin/php
<?PHP

	if ($argc != 2)
	{
		exit;
	}
	if (empty($argv[1]) == TRUE)
	{
		exit;
	}
	if (ctype_space($argv[1]) == TRUE)
	{
		exit;
	}
	$word = explode(" ", $argv[1]);
	foreach ($word as $content)
	{
		if (empty($content) == FALSE)
		{
			$real_word[] = $content;
		}
	}
	print(implode(" ", $real_word));
	echo "\n";
?>
