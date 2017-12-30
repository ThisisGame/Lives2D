//
//  ViewController.m
//  lives2d
//
//  Created by macmini on 2017/10/9.
//  Copyright © 2017年 macmini. All rights reserved.
//

#import "ViewController.h"

#import "lua.h"
#import "lualib.h"
#import "luaconf.h"
#import "lauxlib.h"

#import "tolua++.h"

#import "FreeImage.h"

//#include "ftglyph.h"
//#include "ftbitmap.h"
//
//#include "freetype.h"





@interface ViewController ()

@end

@implementation ViewController

@synthesize glesView=_glesView;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    CGRect screenRect=[[UIScreen mainScreen] bounds];
    self.glesView=[[GLESView alloc] initWithFrame:screenRect];
    [self.view addSubview:self.glesView];
    
    
    
    lua_State* p_Lua_State=luaL_newstate();
    luaL_openlibs(p_Lua_State);
    luaL_dostring(p_Lua_State, "print 'hello lua'");
    lua_close(p_Lua_State);

//    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
//    NSString *docDir = [paths objectAtIndex:0];
//    NSString* pngfilepath=[docDir stringByAppendingPathComponent:@"test.png"];
//    NSLog(@"pngfilepath:%@",pngfilepath);
    
    NSString *imagePath = [[NSBundle mainBundle] pathForResource:@"Data/test" ofType:@"png"];
    NSLog(@"pngfilepath:%@",imagePath);
    UIImage *appleImage = [[UIImage alloc] initWithContentsOfFile:imagePath];
    
    
    FREE_IMAGE_TYPE imageformat=FreeImage_GetFileType([imagePath UTF8String], 0);
    
    NSLog(@"imageformat:%d",imageformat);
    
    FIBITMAP *bitmap=FreeImage_Load(imageformat, [imagePath UTF8String], 0);
    
    if(bitmap==NULL)
    {
        NSLog(@"error image");
    }
    else
    {
        bitmap = FreeImage_ConvertTo32Bits(bitmap);
        
        BYTE *pixels = (BYTE*)FreeImage_GetBits(bitmap);
        int mTextureWidth = FreeImage_GetWidth(bitmap);
        int mTextureHeight = FreeImage_GetHeight(bitmap);
    }
    
    
    //Font tfontt;
//    fontt.buildSystemFont(ttfpath.c_str(), 30);
//
//    bool bRet = font.getCharacter('L');
//    if (bRet)
//    {
//        LOGI("find it .");
//    }
//    else
//    {
//        LOGI("Cannot find it .");
//    }
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
