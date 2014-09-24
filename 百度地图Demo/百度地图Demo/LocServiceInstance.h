//
//  LocServiceInstance.h
//  学学看
//
//  Created by 李康 on 14-9-16.
//  Copyright (c) 2014年 Alison. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BMapKit.h"
@class LocServiceInstance;
#pragma mark  定位
typedef void (^willStartLocatingBlock)(void);                    // 开始定位
typedef void (^didStopLocatingBlock)(void);                       //停止定位
#pragma mark  定位结果
typedef void (^didUpdateUserLocationBlock)(BMKUserLocation *userLocation);  // 定位成功
typedef void (^didFailToLocate)(NSError *error);                            //定位失败
#pragma mark  地理位置编码
typedef void (^ReverseGeoCodeYN)(BOOL YN);
typedef void(^ReverseGeoCodeResultBlock) (BMKReverseGeoCodeResult *result ,BMKSearchErrorCode error);                                           //地理编码结果
#pragma mark  位置检索
typedef void (^GeoCodeSearchYN)(BOOL YN);
typedef void(^GeoCodeSearchResultBlock) (BMKGeoCodeResult *result ,BMKSearchErrorCode error);                                                               //位置检索结果
#pragma mark  位置检索建议
typedef void (^GeoCodeSearchSuggestionYN)(BOOL YN);
typedef void(^GeoCodeSearchSuggestionResultBlock) (BMKSuggestionResult *result ,BMKSearchErrorCode error);                                            //位置检索结果

@interface LocServiceInstance : NSObject
{
    willStartLocatingBlock                  _willStart;
    didStopLocatingBlock                    _didStop;
    didUpdateUserLocationBlock              _didUpdate;
    didFailToLocate                         _didFail;
    
    ReverseGeoCodeYN                        _rgcYN;
    ReverseGeoCodeResultBlock               _rgcResult;
    
    GeoCodeSearchYN                         _gcYN;
    GeoCodeSearchResultBlock                _gcResult;
    
    GeoCodeSearchSuggestionYN               _suggestionYN;
    GeoCodeSearchSuggestionResultBlock      _suggestionResult;
    
}
+ (id)getInstance;
- (void)startLocation;                          //开始定位
- (void)stopLocation;                          //停止定位

- (NSString *)getCityName;                      // 城市名字
- (NSString *)getCityAddress;                   //街道地址
- (CLLocationCoordinate2D)getLocation;          // 经纬度

// 定位Block
- (void)BMKLocationServiceWillStart:(willStartLocatingBlock)willStart didUpdateUserLocationBlock:(didUpdateUserLocationBlock)didUpdate
    didFailToLocate:(didFailToLocate)didFail
    didStopLocatingBlock:(didStopLocatingBlock)didStop;
// 地理编码Block
- (void)BMKGeoCodeSearchReverseGeoCodeOptionWith:(CLLocationCoordinate2D)cllocation   ReverseGeoCodeYN:(ReverseGeoCodeYN)rgcYN
    ReverseGeoCodeResult:(ReverseGeoCodeResultBlock)rgcResult;
// 位置检索Block
- (void)BMKGeoCodeSearchGeoCodeSearchWithCity:(NSString *)city Address:(NSString *)address
    GeoCodeSearchYN:(GeoCodeSearchYN)gcYN
    GeoCodeSearchResult:(GeoCodeSearchResultBlock)gcResult;
// 位置检索建议Block
- (void)BMKGeoCodeSearchGeoCodeSearchSuggestionWithCity:(NSString *)city Address:(NSString *)address
    GeoCodeSearchSuggestionYN:(GeoCodeSearchSuggestionYN)suggestionYN
    GeoCodeSearchSuggestionResult:(GeoCodeSearchSuggestionResultBlock)suggestionResult;

@end
