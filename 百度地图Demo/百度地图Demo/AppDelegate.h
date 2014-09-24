//
//  AppDelegate.h
//  百度地图Demo
//
//  Created by 李康 on 14-9-24.
//  Copyright (c) 2014年 Luck. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BMKMapManager.h"
@interface AppDelegate : UIResponder <UIApplicationDelegate>
{
    BMKMapManager *_mapManager;
}
@property (strong, nonatomic) UIWindow *window;

@end

