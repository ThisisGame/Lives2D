//
//  ViewController.h
//  lives2d
//
//  Created by macmini on 2017/10/9.
//  Copyright © 2017年 macmini. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GLESView.h"


@interface ViewController : UIViewController
{
    GLESView* _glesView;
}
@property (nonatomic,retain) IBOutlet GLESView* glesView;

@end

