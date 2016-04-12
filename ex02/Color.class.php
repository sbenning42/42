<?PHP
class						Color
{
	public static			$verbose = FALSE;
 	public					$red = 0;
	public					$green = 0;
	public					$blue = 0;
	private					$_format = "Color( red: % 3d, green: % 3d, blue: % 3d )";
 
	function				__construct($composant)
	{
		if (isset($composant['rgb']))
			$this->_decompose($composant['rgb']);
		else
		{
	 		$this->red = intval($composant['red']);
			$this->green = intval($composant['green']);
			$this->blue = intval($composant['blue']);
		}
	 	if (Color::$verbose === TRUE)
			printf("$this constructed.".PHP_EOL);
	}
	
	function				__destruct()
	{
	 	if (Color::$verbose === TRUE)
			printf("$this destructed.".PHP_EOL);
	}
	
	function				__toString()
	{
		return sprintf($this->_format, $this->red, $this->green, $this->blue);
	}
	
	public static function	doc()
	{
		if (file_exists('Color.doc.txt') === FALSE)
			return ;
		return file_get_contents('Color.doc.txt');
	}

	public function			add($c)
	{
		return (new Color(array('red' => ($this->red + $c->red) & 0xff, 'green' => ($this->green + $c->green) & 0xff, 'blue' => ($this->blue + $c->blue) & 0xff)));
	}
 	
	public function			sub($c)
	{
		return (new Color(array('red' => ($this->red - $c->red) & 0xff, 'green' => ($this->green - $c->green) & 0xff, 'blue' => ($this->blue - $c->blue) & 0xff)));
	}

	public function			mult($fact)
	{
		return new Color(array('red' => ($this->red * $fact) & 0xff, 'green' => ($this->green * $fact) & 0xff, 'blue' => ($this->blue * $fact) & 0xff));
	}

	private function		_decompose($composant)
	{
		$this->blue = intval($composant) & 0xff;
		$this->green = intval($composant) >> 8 & 0xff;
		$this->red = intval($composant) >> 16 & 0xff;
	}
}
?>
