#!/usr/bin/php
<?PHP
$file = fopen("/var/run/utmpx", "r");

while ($binstr = fread($file, 628))
{
	$arr[] = unpack("a256user/a4id/a32line/ipid/itype/I2date", $binstr);
}
date_default_timezone_set("Europe/Paris");
foreach ($arr as $tty)
{
	if ($tty["type"] != 7)
	{
		continue ;
	}
	print($tty["user"]." ".$tty["line"]."  ".date( "M  j H:i", $tty["date1"])."\n");

}
?>
