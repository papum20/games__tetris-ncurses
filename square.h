
//x AND y RELATIVE TO PARENT

class Square {
	protected:
		float x, y;
	public:
		Square(float x, float y);
		Square();
		float getX();
		float getY();
		void rotateAroundOrigin();
		//geometrical transformation for 90 degrees rotation around center
		void unRotateAroundOrigin();
		//-90 degrees rotation
};
