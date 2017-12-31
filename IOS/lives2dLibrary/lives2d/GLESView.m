//
//  GLESView.m
//  lives2d
//
//  Created by macmini on 2017/10/9.
//  Copyright © 2017年 macmini. All rights reserved.
//  Code copy fron blog http://blog.csdn.net/wanglixin1999/article/details/51792505
//

#import "GLESView.h"

#include"LuaEngine/LuaEngine.h"
#include"Tools/Application.h"
extern void AudioCardInit();

#include <time.h>

@implementation GLESView


//就看成是override吧 http://blog.csdn.net/sico2sico/article/details/52851755 每个UIView都是挂在一个CALayer实例上，如果要创建其他的，比如GL的，就要挂在CAEAGLLayer上，在layerClass 被调用的时候返回类型
+(Class)layerClass
{
    return [CAEAGLLayer class];
}

-(id)initWithFrame:(CGRect)frame
{
    self=[super initWithFrame: frame];
    if(self)
    {
        [self setupLayer];
        [self setupContext];
        
        [self setupRenderBuffer];
        [self setupFrameBuffer];
        
        [self OnInit];
        
        [self setupDisplayLink];
    }
    return self;
}


//设置Layer为不透明
-(void)setupLayer
{
    mCAEAGLLayer=(CAEAGLLayer*)self.layer;
    mCAEAGLLayer.opaque=YES;
}

//创建OpenGL Context(上下文)
-(void)setupContext
{
    mEAGLContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    if(!mEAGLContext)
    {
        NSLog(@"setupContext [EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2 Failed");
        return;
    }
    
    if(![EAGLContext setCurrentContext:mEAGLContext])
    {
        NSLog(@"setupContext [EAGLContext setCurrentContext:mEAGLContext] Failed");
        return;
    }
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    //取得所点击的点的坐标
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint point = [touch locationInView:self];
    
    
    int tmpX = point.x;
    int tmpY = point.y;
    
    //转换成零点在屏幕窗口中间，右上增长的坐标
    tmpX = tmpX - Application::ScreenWidth / 2;
    tmpY = Application::ScreenHeight /2 - tmpY;
    
    
    //适配设计分辨率
    float tmpWidthRatio = Application::RenderWidth / (float)Application::DesignWidth;
    float tmpHeightRatio = Application::RenderHeight / (float)Application::DesignHeight;
    
    tmpX = tmpX/tmpWidthRatio;
    tmpY = tmpY/tmpHeightRatio;
    
    //Lives2D::OnTouch(tmpX, tmpY);
    std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
    {
        tolua_pushnumber(var_pLuaState, tmpX);
        tolua_pushnumber(var_pLuaState, tmpY);
    };
    LuaEngine::GetSingleton()->CallLuaFunction("OnTouch", 2, tmpFunction);
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint point = [touch locationInView:self];
    
    
    int tmpX = point.x;
    int tmpY = point.y;
    
    //转换成零点在屏幕窗口中间，右上增长的坐标
    tmpX = tmpX - Application::ScreenWidth / 2;
    tmpY = Application::ScreenHeight / 2 - tmpY;
    
    //适配设计分辨率
    float tmpWidthRatio = Application::RenderWidth / (float)Application::DesignWidth;
    float tmpHeightRatio = Application::RenderHeight / (float)Application::DesignHeight;
    
    tmpX = tmpX / tmpWidthRatio;
    tmpY = tmpY / tmpHeightRatio;
    
    std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
    {
        tolua_pushnumber(var_pLuaState, tmpX);
        tolua_pushnumber(var_pLuaState, tmpY);
    };
    LuaEngine::GetSingleton()->CallLuaFunction("OnTouchRelease", 2, tmpFunction);
}


-(void)OnInit
{
    
    AudioCardInit();
    
    NSString *dataPath = [[NSBundle mainBundle] bundlePath];
    
    Application::SetDataPath([dataPath UTF8String]);
    Application::SetPersistentDataPath([dataPath UTF8String]);
    
    glClearColor(1, 0, 0, 1);
    
    glViewport(0, 0, (GLsizei)self.frame.size.width, (GLsizei)self.frame.size.height);
    
    
    
    Application::ScreenWidth=self.frame.size.width;
    Application::ScreenHeight=self.frame.size.height;
    
    
    //LuaEngine Start
    LuaEngine::GetSingleton()->DoFile((Application::PersistentDataPath()+ "/Resource/Script/Engine/Lives2D.lua").c_str());
    
    std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
    {
        tolua_pushnumber(var_pLuaState, Application::ScreenWidth);
        tolua_pushnumber(var_pLuaState, Application::ScreenHeight);
    };
    LuaEngine::GetSingleton()->CallLuaFunction("Init",2, tmpFunction);
}

-(void)setupDisplayLink
{
    CADisplayLink *displayLink=[CADisplayLink displayLinkWithTarget:self selector:@selector(Step:)];
    [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
}


//创建渲染缓冲区-颜色缓冲区
-(void)setupRenderBuffer
{
    glGenRenderbuffers(1, &mColorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, mColorRenderBuffer);
    [mEAGLContext renderbufferStorage:GL_RENDERBUFFER fromDrawable:mCAEAGLLayer];
}

//创建帧缓冲区
-(void)setupFrameBuffer
{
    GLuint framebuffer;
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,GL_RENDERBUFFER, mColorRenderBuffer);
}

-(void)Update:(float)varDeltaTime
{
    std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
    {
        tolua_pushnumber(var_pLuaState, varDeltaTime);
    };
    LuaEngine::GetSingleton()->CallLuaFunction("Update", 1, tmpFunction);
}

-(void)Step:(CADisplayLink*)varCADisplayLink
{
    static float frameTime=1.0f/60;
    static NSTimeInterval begintime=[[NSDate date] timeIntervalSince1970]*1000;
    static NSTimeInterval endtime=[[NSDate date] timeIntervalSince1970]*1000;
    static float deltaTime=0.0f;

    deltaTime=(endtime-begintime)/1000.0f;
    if(deltaTime>frameTime)
    {
        begintime=[[NSDate date] timeIntervalSince1970]*1000;
        //NSLog(@"%f",deltaTime);
        [self Update:deltaTime];
        [self Render:varCADisplayLink];
    }
    endtime=[[NSDate date] timeIntervalSince1970]*1000;
}

-(void)Render:(CADisplayLink*)varCADisplayLink
{
    if(Application::isRunning==false)
    {
        return;
    }
    
    glClearColor(1,0,0,1);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    
    //保持画面比例 进行缩放 会出现黑边
    float tmpDesignRatio = (float)Application::DesignWidth / Application::DesignHeight;
    float tmpScreenRatio = (float)Application::ScreenWidth / Application::ScreenHeight;
    if (tmpScreenRatio > tmpDesignRatio)//更宽,取heihgt做适配,width做黑边
    {
        Application::RenderWidth = Application::DesignWidth*((float)Application::ScreenHeight/Application::DesignHeight);
        Application::RenderHeight = Application::ScreenHeight;
    }
    else if (tmpScreenRatio < tmpDesignRatio)//更高,取width做适配,height做黑边
    {
        Application::RenderWidth = Application::ScreenWidth;
        Application::RenderHeight = Application::DesignHeight*((float)Application::ScreenWidth/Application::DesignWidth);
    }
    else
    {
        Application::RenderWidth = Application::ScreenWidth;
        Application::RenderHeight = Application::ScreenHeight;
    }
    
    float viewportoffsetWidth = (Application::ScreenWidth - Application::RenderWidth) / 2;
    float viewportoffsetHeight = (Application::ScreenHeight - Application::RenderHeight) / 2;
    glViewport(viewportoffsetWidth, viewportoffsetHeight, Application::RenderWidth, Application::RenderHeight);
    
    LuaEngine::GetSingleton()->CallLuaFunction("Draw");
    
    [mEAGLContext presentRenderbuffer:GL_RENDERBUFFER];
}

@end
