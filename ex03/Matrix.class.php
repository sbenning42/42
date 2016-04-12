<?PHP
require_once 'Vector.class.php';

class						Matrix
{
	const 					IDENTITY = 0;
	const 					SCALE = 1;
	const 					RX = 2;
	const 					RY = 3;
	const 					RZ = 4;
	const 					TRANSLATION = 5;
	const 					PROJECTION = 6;

	public static			$verbose = FALSE;
	private					$_vc_x;
	private					$_vc_y;
	private					$_vc_z;
	private					$_vc_w;
	private					$_vt;
	private					$_format = "M | vtcX | vtcY | vtcZ | vtxO\n-----------------------------\nx | %.2f | %.2f | %.2f | %.2f\ny | %.2f | %.2f | %.2f | %.2f\nz | %.2f | %.2f | %.2f | %.2f\nw | %.2f | %.2f | %.2f | %.2f";

	public function			__construct($transformation)
	{
		if (!isset($transformation['preset']))
			exit ;
		switch ($transformation['preset'])
		{
			case Matrix::IDENTITY:
				$this->_identity();
				if (Matrix::$verbose === TRUE)
					print('Matrix IDENTITY instance constructed'.PHP_EOL);
				break ;
			case Matrix::SCALE:
				if (!isset($transformation['scale']))
					exit;
				break ;
			case Matrix::RX:
			case Matrix::RY:
			case Matrix::RZ:
				if (!isset($transformation['angle']))
					exit;
				break ;
			case Matrix::TRANSLATION:
				if (!isset($transformation['vtc']))
					exit;
				$this->_translation($transformation['vtc']);
				if (Matrix::$verbose === TRUE)
					print('Matrix IDENTITY instance constructed'.PHP_EOL);
				break ;
			case Matrix::PROJECTION:
				if (!isset($transformation['fov']) OR !isset($transformation['ratio']) OR !isset($transformation['near']) OR !isset($transformation['far']))
					exit;
			 	break ;
			default:
				exit ;
		}
	}

	public function			__destruct()
	{
		if (Matrix::$verbose === TRUE)
 			print("Matrix instance destructed".PHP_EOL);
	}

	public function			__toString()
	{
		return sprintf($this->_format, $this->_vc_x->getX(), $this->_vc_y->getX(), $this->_vc_z->getX(), $this->_vt->getX(),
										$this->_vc_x->getY(), $this->_vc_y->getY(), $this->_vc_z->getY(), $this->_vt->getY(),
										$this->_vc_x->getZ(), $this->_vc_y->getZ(), $this->_vc_z->getZ(), $this->_vt->getZ(),
										$this->_vc_x->getW(), $this->_vc_y->getW(), $this->_vc_z->getW(), $this->_vt->getW());
	}

	public static function	doc()
	{
		if (file_exists('Matrix.doc.txt'))
			return file_get_contents('Matrix.doc.txt');
	}

	public function			getVc_x()
	{
		return $this->_vc_x;
	}

	public function			getVc_y()
	{
		return $this->_vc_y;
	}

	public function			getVc_z()
	{
		return $this->_vc_z;
	}

	public function			getVc_w()
	{
		return $this->_vc_w;
	}

/*
	public function 		mult($matrice)
	{
	}

	public function 		transformVertex($vertex)
	{
	}
 */
	private function		_identity()
	{
		$this->_vc_x = new Vector(array('dest' => new Vertex(array('x' => 1.0, 'y' => 0.0, 'z' => 0.0))));
		$this->_vc_y = new Vector(array('dest' => new Vertex(array('x' => 0.0, 'y' => 1.0, 'z' => 0.0))));
		$this->_vc_z = new Vector(array('dest' => new Vertex(array('x' => 0.0, 'y' => 0.0, 'z' => 1.0))));
		$this->_vt = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0));
	}

	private function		_translation($vtc)
	{
		$this->_identity();
		$this->_vt->setX($vtc->getX());
		$this->_vt->setY($vtc->getY());
		$this->_vt->setZ($vtc->getZ());
	}

	private function		_scale($scale)
	{
		$this->_identity();
		$this->_vt->setX($vtc->getX());
		$this->_vt->setY($vtc->getY());
		$this->_vt->setZ($vtc->getZ());
	}
}
?>
