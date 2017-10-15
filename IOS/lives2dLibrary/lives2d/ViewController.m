//
//  ViewController.m
//  lives2d
//
//  Created by macmini on 2017/10/9.
//  Copyright © 2017年 macmini. All rights reserved.
//

#import "ViewController.h"

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
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
