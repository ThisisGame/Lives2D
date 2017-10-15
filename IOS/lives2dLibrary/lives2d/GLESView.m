//
//  GLESView.m
//  lives2d
//
//  Created by macmini on 2017/10/9.
//  Copyright © 2017年 macmini. All rights reserved.
//  Code copy fron blog http://blog.csdn.net/wanglixin1999/article/details/51792505
//

#import "GLESView.h"

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
        [self Render];
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

-(void)setupDisplayLink
{
    CADisplayLink *displayLink=[CADisplayLink displayLinkWithTarget:self selector:@selector(Render)];
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

-(void)Render
{
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    [mEAGLContext presentRenderbuffer:GL_RENDERBUFFER];
}

@end
