//
//  BMKLocationService.h
//  LocationComponent
//
//  Created by Baidu on 3/28/14.
//  Copyright (c) 2014 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BMKUserLocation.h"
@class CLLocation;
/// 定位服务Delegate,调用startUserLocationService定位成功后，用此Delegate来获取定位数据
@protocol BMKLocationServiceDelegate <NSObject>
@optional
/**
 *在将要启动定位时，会调用此函数
 */
- (void)willStartLocatingUser;

/**
 *在停止定位后，会调用此函数
 */
- (void)didStopLocatingUser;

/**
 *用户方向更新后，会调用此函数
 *@param userLocation 新的用户位置
 */
- (void)didUpdateUserHeading:(BMKUserLocation *)userLocation;

/**
 *用户位置更新后，会调用此函数
 *@param userLocation 新的用户位置
 */
- (void)didUpdateUserLocation:(BMKUserLocation *)userLocation;

/**
 *定位失败后，会调用此函数
 *@param error 错误号
 */
- (void)didFailToLocateUserWithError:(NSError *)error;
@end

@interface BMKLocationService : NSObject

/// 当前用户位置，返回坐标为百度坐标
@property (nonatomic, readonly) BMKUserLocation *userLocation;

/// 定位服务Delegate,调用startUserLocationService定位成功后，用此Delegate来获取定位数据
@property (nonatomic, assign) id<BMKLocationServiceDelegate> delegate;

/**
 *打开定位服务
 */
-(void)startUserLocationService;
/**
 *关闭定位服务
 */
-(void)stopUserLocationService;

@end
