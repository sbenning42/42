#!/usr/bin/php
<?PHP
if ($argc < 2)
{
	exit ;
}
$pattern[] = "/\s+/";
$pattern[] = "/^\s+/";
$pattern[] = "/\s+$/";
$rep[] = " ";
print(preg_replace($pattern, $rep, $argv[1])."\n");
?>
