#!/usr/bin/php
<?PHP

echo "Entrez un nombre: ";

$len = strlen(($str = fgets(fopen("php://stdin", "r"))));
if ($len < 1)
{
	echo "^D\n";
	exit;
}
$len = strlen($str = rtrim($str));
if ($len == 0 OR is_numeric($str) == False)
{
	echo "'$str' n'est pas un chiffre\n";
	exit;
}
$str = trim($str);
if (is_int($str + 0) == FALSE)
{
	echo "'$str' n'est pas un chiffre\n";
	exit;
}
if ($str % 2 == 0)
{
	echo "Le chiffre $str est Pair\n";
}
else
{
	echo "Le chiffre $str est Impair\n";
}
?>
