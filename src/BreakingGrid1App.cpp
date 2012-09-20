#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define GRID_NUM 20

class BreakingGrid1App : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
    void mouseMove( MouseEvent event );
	void update();
	void draw();
    
    float mGridSizeX;
    float mGridSizeY;
    
    float mSize;
    float mRandMax;
};

void BreakingGrid1App::prepareSettings( Settings *settings )
{
    settings->setWindowSize(700, 700);
}

void BreakingGrid1App::setup()
{
    mGridSizeX = (float)getWindowWidth() / GRID_NUM;
    mGridSizeY = (float)getWindowHeight() / GRID_NUM;
    
    mSize = 5.0f;
    
    gl::enableAlphaBlending();
    glLineWidth(mSize/2);
}

void BreakingGrid1App::mouseDown( MouseEvent event )
{
}

void BreakingGrid1App::mouseMove( MouseEvent event )
{
    
    mSize = lmap((float)event.getX(), 0.0f, (float)getWindowWidth(), 0.0f, 30.0f);
    
    mRandMax = lmap((float)event.getY(), 0.0f, (float)getWindowHeight(), 0.0f, 10.0f);
}


void BreakingGrid1App::update()
{
    glLineWidth(mSize/2);
}

void BreakingGrid1App::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );
    gl::color(0, 0, 0, 0.5);
    for (int yNum = 0; yNum < GRID_NUM; yNum++) {
        for (int xNum = 0; xNum < GRID_NUM; xNum++) {
            Vec2f center = Vec2f(xNum * mGridSizeX + mGridSizeX * 0.5 ,yNum * mGridSizeY + mGridSizeY * 0.5);
            Vec2f randVec = Vec2f(Rand::randFloat(-mRandMax, mRandMax), Rand::randFloat(-mRandMax, mRandMax));
            
            center += randVec;
            
            gl::pushMatrices();
            gl::translate(center);
            gl::drawStrokedCircle(Vec2f::zero(), mSize);
            
            gl::popMatrices();
            
        }
    }
}

CINDER_APP_BASIC( BreakingGrid1App, RendererGl )
