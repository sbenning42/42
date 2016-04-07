#!/usr/bin/php
<?PHP

if ($argc < 2)
{
	exit ;
}
	preg_match("/https?:\/\/(.*)$/", $argv[1], $namear);
	if (!($name = $namear[1]))
	{
		exit ;
	}
	if (!is_dir($name))
	{
		mkdir($name, 0777);
	}
	$content = file_get_contents($argv[1]);
	if (preg_match_all('/<img src="([^"]*)".*>/', $content, $img_url, PREG_PATTERN_ORDER))
	{
		print_r($img_url);
		$img_url = array_slice($img_url, 1);
		foreach ($img_url[0] as $img)
		{
			echo "img url: $img\n";
			preg_match('/\/([^\/]*)$/', $img, $img_namear);
			$img_name = $img_namear[1];
			echo "img name: $img_name\n";
			file_put_contents($name . "/" . $img_name, file_get_contents($img));
		}
	}

?>
