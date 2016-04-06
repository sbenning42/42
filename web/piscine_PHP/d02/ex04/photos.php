#!/usr/bin/php
<?PHP

if ($argc < 2)
{
	exit ;
}
$arg = array_slice($argv, 1);
foreach ($arg as $url)
{
	preg_match('/https?:\/\/(.*?)$/', $url, $namear);
	if (!($name = $namear[1]))
	{
		continue ;
	}
	mkdir($name, 0777);
	$net = curl_init($url);
	curl_setopt($net, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($net, CURLOPT_USERAGENT, 'sb piscine PHP 42');
	$content = curl_exec ($net);
	curl_close($net);
	if (preg_match_all('/<img src="(.*?)".*>/', $content, $img_url, PREG_PATTERN_ORDER))
	{
		$img_url = array_slice($img_url, 1);
		foreach ($img_url[0] as $img)
		{
			preg_match('/\/([^\/]*?)$/', $img, $img_namear);
			$img_name = $img_namear[1];
			$net_img = curl_init($img);
			curl_setopt($net_img, CURLOPT_RETURNTRANSFER, 1);
			curl_setopt($net_img, CURLOPT_BINARYTRANSFER, 1);
			curl_setopt($net_img, CURLOPT_USERAGENT, 'sb piscine PHP 42');
			$binimg = curl_exec ($net_img);
			curl_close($net_img);
			file_put_contents($name . "/" . $img_name, $binimg);
		}
	}
}

?>
