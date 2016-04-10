#!/usr/bin/php
<?PHP
include ("product_table_handle.php");

category_add_entry("Red-Rabbit");
category_add_entry("Element");
category_add_entry("Blackkross");
category_add_entry("Deck");
category_add_entry("Weels");
category_add_entry("Truck");
product_add_entry("board0", array("Red-Rabbit", "Deck"), "");
product_add_entry("board1", array("Element", "Deck"), "");
product_add_entry("board2", array("Blackkross", "Deck"), "");
product_add_entry("Truck0", array("Red-Rabbit", "Truck"), "img/Truck0.png");
product_add_entry("Truck1", array("Element", "Truck"), "img/Truck1.png");
product_add_entry("Truck2", array("Blackkross", "Truck"), "img/Truck2.png");
product_add_entry("Weels0", array("Red-Rabbit", "Weels"), "");
product_add_entry("Weels1", array("Element", "Weels"), "");
product_add_entry("Weels2", array("Blackkross", "Weels"), "");
table_dump(0);

$category = category_get_product("Truck");
foreach ($category as $product)
{
	$product['img'] = preg_replace("/img\/(.*)\.png/", "/img\/NEW_$1\.png/", $product['img']);
	product_modif($product);
}
 
table_dump(1);
?>
