//
//  SYACyclePageView.h
//  SYACyclePageViewDemo
//
//  Created by zq on 2017/12/13.
//  Copyright © 2017年 www.lejiakeji.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SYACyclePageTransformLayout.h"
NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, SYAPageScrollDirection) {
    SYAPageScrollDirectionLeft,
    SYAPageScrollDirectionRight,
};
@class SYACyclePageView;
@protocol SYACyclePagerViewDataSource <NSObject>

- (NSInteger)numberOfItemsInPagerView:(SYACyclePageView *)pageView;

- (__kindof UICollectionViewCell *)pagerView:(SYACyclePageView *)pagerView cellForItemAtIndex:(NSInteger)index;

- (SYACyclePageViewLayout *)layoutForPagerView:(SYACyclePageView *)pageView;

@end

@protocol SYACyclePageViewDelegate <NSObject>

@optional

- (void)pagerView:(SYACyclePageView *)pageView didScrollFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;

- (void)pagerView:(SYACyclePageView *)pageView didSelectedItemCell:(__kindof UICollectionViewCell *)cell atIndex:(NSInteger)index;

- (void)pagerView:(SYACyclePageView *)pageView initializeTransformAttributes:(UICollectionViewLayoutAttributes *)attributes;

- (void)pagerView:(SYACyclePageView *)pageView applyTransformToAttributes:(UICollectionViewLayoutAttributes *)attributes;


// scrollViewDelegate

- (void)pagerViewDidScroll:(SYACyclePageView *)pageView;

- (void)pagerViewWillBeginDragging:(SYACyclePageView *)pageView;

- (void)pagerViewDidEndDragging:(SYACyclePageView *)pageView willDecelerate:(BOOL)decelerate;

- (void)pagerViewWillBeginDecelerating:(SYACyclePageView *)pageView;

- (void)pagerViewDidEndDecelerating:(SYACyclePageView *)pageView;

- (void)pagerViewWillBeginScrollingAnimation:(SYACyclePageView *)pageView;

- (void)pagerViewDidEndScrollingAnimation:(SYACyclePageView *)pageView;

@end
@interface SYACyclePageView : UIView

@property (nonatomic, strong, nullable) UIView *backgroundView;

@property (nonatomic, weak, nullable) id<SYACyclePagerViewDataSource> dataSource;

@property (nonatomic, weak, nullable) id<SYACyclePageViewDelegate> delegate;

@property (nonatomic, weak, readonly) UICollectionView *collectionView;

@property (nonatomic, strong, readonly) SYACyclePageViewLayout *layout;

@property (nonatomic, assign) BOOL isInfiniteLoop;

@property (nonatomic, assign) CGFloat autoScrollInterval;

@property (nonatomic, assign, readonly) NSInteger curIndex;

@property (nonatomic, assign, readonly) CGPoint contentOffset;

@property (nonatomic, assign, readonly) BOOL tracking;

@property (nonatomic, assign, readonly) BOOL dragging;

@property (nonatomic, assign, readonly) BOOL decelerating;

- (void)reloadData;

- (void)updateData;

- (void)setNeedUpdateLayout;

- (void)setNeedClearLayout;

- (__kindof UICollectionViewCell * _Nullable)curIndexCell;

- (NSArray<__kindof UICollectionViewCell *> *_Nullable)visibleCells;

- (NSArray *)visibleIndexs;

- (void)scrollToItemAtIndex:(NSInteger)index animate:(BOOL)animate;

- (void)scrollToNearlyIndexAtDirection:(SYAPageScrollDirection)direction animate:(BOOL)animate;

- (void)registerClass:(Class)Class forCellWithReuseIdentifier:(NSString *)identifier;

- (void)registerNib:(UINib *)nib forCellWithReuseIdentifier:(NSString *)identifier;

- (__kindof UICollectionViewCell *)dequeueReusableCellWithReuseIdentifier:(NSString *)identifier forIndex:(NSInteger)index;
@end
NS_ASSUME_NONNULL_END
