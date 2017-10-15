//
//  GLESView.h
//  lives2d
//
//  Created by macmini on 2017/10/9.
//  Copyright © 2017年 macmini. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

@interface GLESView : UIView
{
    CAEAGLLayer* mCAEAGLLayer;
    EAGLContext* mEAGLContext;
    GLuint mColorRenderBuffer;
}
@end
