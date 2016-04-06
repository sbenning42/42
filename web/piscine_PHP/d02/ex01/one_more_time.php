#!/usr/bin/php
<?PHP
if ($argc < 2)
{
	exit ;
}
$match = array();
if (preg_match("/^([A-Za-z][a-z]*) (\d{1,2}) ([A-Za-z][a-z]*) (\d{4}) (\d{2}):(\d{2}):(\d{2})$/", $argv[1], $match) === 0)
{
	echo "Wrong Format\n";
	exit ;
}
$match[1] = strtolower($match[1]);
$match[3] = strtolower($match[3]);

$day[] = "lundi";
$day[] = "mardi";
$day[] = "mercredi";
$day[] = "jeudi";
$day[] = "venderdi";
$day[] = "samedi";
$day[] = "dimanche";

$month[] = "janvier";
$month[] = "fevrier";
$month[] = "mars";
$month[] = "avril";
$month[] = "mai";
$month[] = "juin";
$month[] = "juillet";
$month[] = "aout";
$month[] = "septembre";
$month[] = "octobre";
$month[] = "novembre";
$month[] = "decembre";

if (array_search($match[1], $day) === FALSE OR ($index = array_search($match[3], $month)) === FALSE OR $match[2] < 1 OR $match[2] > 31 OR $match[5] > 23 OR $match[6] > 59 OR $match[7] > 59)
{
	echo "Wrong Format\n";
	exit ;
}
$index++;
if ((($index == 4 OR $index == 6 OR $index == 9 OR $index == 11) AND $match[2] > 30) OR ($index == 2 AND $match[2] > 28))
{
	echo "Wrong Format\n";
	exit ;
}
$date = $match[4].":";
if ($index < 10)
{
	$date .= "0";
}
$date .= $index.":";
if (strlen($match[2]) < 2)
{
	$date .= "0";
}
$date .= $match[2]." ".$match[5].":".$match[6].":".$match[7];

date_default_timezone_set("Europe/Paris");
print(strtotime($date)."\n");
?>
