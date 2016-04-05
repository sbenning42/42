<?PHP
function ft_is_sort($tab)
{
	if ($tab == NULL)
	{
		return FALSE;
	}
	asort($tab);
	$i = 0;
	$sort = TRUE;
	foreach ($tab as $key => $content)
	{
		if ($key > $i++)
		{
			$sort = FALSE;
			break ;
		}
	}
	if ($sort == TRUE)
	{
		return TRUE;
	}
	$sort = TRUE;
	$len = sizeof($tab) - 1;
	foreach ($tab as $key => $content)
	{
		if ($key < $len--)
		{
			$sort = FALSE;
			break ;
		}
	}
	return $sort;
}
?>
