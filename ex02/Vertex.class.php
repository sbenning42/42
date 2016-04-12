<?PHP
require_once 'Color.class.php';

class						Vertex
{
	public static			$verbose = FALSE;
	private					$_x;
	private					$_y;
	private					$_z;
	private					$_w = 1.0;
	private					$_color;
	private					$_vformat = 'Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, %s )';
	private					$_format = 'Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f )';

	public function			__construct($vertex)
	{
		if (!isset($vertex['x']) OR !isset($vertex['y']) OR !isset($vertex['z']))
			exit ;
		$this->_x = $vertex['x'];
		$this->_y = $vertex['y'];
		$this->_z = $vertex['z'];
		if (isset($vertex['w']))
			$this->_w = $vertex['w'];
		if (isset($vertex['color']) AND get_class($vertex['color']) === 'Color')
			$this->_color = $vertex['color'];
		else
			$this->_color = new Color(array('rgb' => 0xffffff));
		if (Vertex::$verbose === TRUE)
			print($this." constructed".PHP_EOL);
	}

	public function			__destruct()
	{
		if (Vertex::$verbose === TRUE)
 			print($this." destructed".PHP_EOL);
	}

	function				__toString()
	{
		if (Vertex::$verbose === TRUE)
			return sprintf($this->_vformat, $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
 		return sprintf($this->_format, $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public static function	doc()
	{
		if (file_exists('Vertex.doc.txt'))
			return file_get_contents('Vertex.doc.txt');
	}

	public function			getX()
	{
		return $this->_x;
	}

	public function			setX($x)
	{
		$this->_x = $x;
	}

	public function			getY()
	{
		return $this->_y;
	}

	public function			setY($y)
	{
		$this->_y = $y;
	}

	public function			getZ()
	{
		return $this->_z;
	}

	public function			setZ($z)
	{
		$this->_z = $z;
	}

	public function			getW()
	{
		return $this->_w;
	}

	public function			setW($w)
	{
		$this->_w = $w;
	}

	public function			getColor()
	{
		return $this->_color;
	}

	public function			setColor($color)
	{
		$this->_color = $color;
	}
}
?>
