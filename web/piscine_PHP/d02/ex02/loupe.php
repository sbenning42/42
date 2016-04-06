#!/usr/bin/php
<?PHP

function up_title($array)
{
	print_r($array);
	return ("<a" . $array[1] . 'title="' . strtoupper($array[2] . '"'));
}

function up_str($array)
{
	print_r($array);
	return ("<a" . $array[1] . ">" . strtoupper($array[2] . '<'));
}

if ($argc != 2)
{
	exit ;
}
$file = file_get_contents($argv[1]);

$reg = '/<a([\s\S]*?)title="([\s\S]*?)"/';
$file = preg_replace_callback($reg, "up_title", $file);
 /*$reg = '/<a(.*?)>(.*?)</';
$file = preg_replace_callback($reg, "up_str", $file);*/
echo "$file";
?>
