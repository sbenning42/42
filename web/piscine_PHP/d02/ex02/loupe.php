#!/usr/bin/php
<?PHP

function up_three($array)
{
	return ('title="'. strtoupper($array[1]) .'"');
}

function up_two($array)
{
	return (">". strtoupper($array[1]) ."<");
}

function up_first($array)
{
	$reg = "/>(.*)</iUs";
	$array[3] = preg_replace_callback($reg, "up_two", $array[3]);
	$reg = '/title="(.*)"/iUs';
	$array[3] = preg_replace_callback($reg, "up_three", $array[3]);
	if (!empty($array[2]))
	{
		return ("<a" . $array[1] . 'title="' . strtoupper($array[2]) . '"' . $array[3] . "/a>");
	}
	return ("<a" . $array[1] . $array[3] . "/a>");

}

if ($argc != 2)
{
	exit ;
}
$file = file_get_contents($argv[1]);
$reg = '/<a(.*)(?:title="(.*)")?(>.*<)\/a>/iUs';
$file = preg_replace_callback($reg, "up_first", $file);
print($file);

?>
