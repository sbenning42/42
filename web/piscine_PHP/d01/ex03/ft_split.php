<?PHP
function ft_split($str)
{
	$tab = explode(" ", $str);
	foreach ($tab as $content)
	{
		if (empty($content) == FALSE)
		{
			$word[] = $content;
		}
	}
	asort($word);
	#sort($word, SORT_STRING);
	return ($word);
}
?>
