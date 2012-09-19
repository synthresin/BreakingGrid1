#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BreakingGrid1App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void BreakingGrid1App::setup()
{
}

void BreakingGrid1App::mouseDown( MouseEvent event )
{
}

void BreakingGrid1App::update()
{
}

void BreakingGrid1App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( BreakingGrid1App, RendererGl )
