<?PHP
require_once "Vertex.class.php";

class						Vector
{
	public static			$verbose = FALSE;
	private					$_x;
	private					$_y;
	private					$_z;
	private					$_w = 0.00;
	private					$_format = 'Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )';

	public function			__construct($vertex)
	{
		if (!isset($vertex['dest']) OR get_class($vertex['dest']) != "Vertex")
			exit;
		if (!isset($vertex['orig']) OR get_class($vertex['orig']) != "Vertex")
			$vertex['orig'] = new Vertex(array('x' => 0.0, 'y' => 0.0, 'z' => 0.0));
		$this->_x = $vertex['dest']->getX() - $vertex['orig']->getX();
		$this->_y = $vertex['dest']->getY() - $vertex['orig']->getY();
		$this->_z = $vertex['dest']->getZ() - $vertex['orig']->getZ();
		if (Vector::$verbose === TRUE)
			print($this." constructed".PHP_EOL);
	}

	public function			__destruct()
	{
		if (Vector::$verbose === TRUE)
 			print($this." destructed".PHP_EOL);
	}

	public function			__toString()
	{
 		return sprintf($this->_format, $this->_x, $this->_y, $this->_z, $this->_w);
	}

	public static function	doc()
	{
		if (file_exists('Vector.doc.txt'))
			return file_get_contents('Vector.doc.txt');
	}

	public function			getX()
	{
		return $this->_x;
	}

	public function			getY()
	{
		return $this->_y;
	}
	
	public function			getZ()
	{
		return $this->_z;
	}
	
	public function			getW()
	{
		return $this->_w;
	}

	public function			magnitude()
	{
		return sqrt($this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z);
	}

	public function			dotProduct($v)
	{
		return $this->_x * $v->getX() + $this->_y * $v->getY() + $this->_z * $v->getZ();
	}

	public function			cos($v)
	{
		return $this->dotProduct($v) / ($this->magnitude() * $v->magnitude());
	}

	public function			normalize()
	{
		return new Vector(array('dest' => new Vertex(array(
															'x' => $this->_x / $this->magnitude(),
															'y' => $this->_y / $this->magnitude(),
															'z' => $this->_z / $this->magnitude()
															))));
	}

	public function			add($v)
	{
		return new Vector(array('dest' => new Vertex(array(
															'x' => $this->_x + $v->getX(),
															'y' => $this->_y + $v->getY(),
															'z' => $this->_z + $v->getZ()
															))));
	}

	public function			sub($v)
	{
		return new Vector(array('dest' => new Vertex(array(
															'x' => $this->_x - $v->getX(),
															'y' => $this->_y - $v->getY(),
															'z' => $this->_z - $v->getZ()
															))));
	}

	public function			scalarProduct($scal)
	{
		return new Vector(array('dest' => new Vertex(array(
															'x' => $this->_x * $scal,
															'y' => $this->_y * $scal,
															'z' => $this->_z * $scal
															))));
	}

	public function			crossProduct($v)
	{
		return new Vector(array('dest' => new Vertex(array('x' => $this->_y * $v->getZ() - $this->_z * $v->getY(),
															'y' => $this->_z * $v->getX() - $this->_x * $v->getZ(),
															'z' => $this->_x * $v->getY() - $this->_y * $v->getX()
															))));
	}

	public function			opposite()
	{
		return $this->scalarProduct(-1);
	}
}
?>
