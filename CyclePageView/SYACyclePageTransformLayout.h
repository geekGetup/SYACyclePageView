//
//  SYACyclePageTransformLayout.h
//  SYACyclePageViewDemo
//
//  Created by zq on 2017/12/13.
//  Copyright © 2017年 www.lejiakeji.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SYACyclePageTransformLayoutType) {
    SYACyclePageTransformLayoutNormal,
    SYAyclePageTransformLayoutLinear,
    SYACyclePageTransformLayoutCoverflow,
};
@class SYACyclePageTransformLayout;
@protocol SYACyclePageTransformLayoutDelegate <NSObject>

- (void)pageViewTransformLayout:(SYACyclePageTransformLayout *)pageViewTransformLayout initializeTransformAttributes:(UICollectionViewLayoutAttributes *)attributes;

- (void)pageViewTransformLayout:(SYACyclePageTransformLayout *)pageViewTransformLayout applyTransformToAttributes:(UICollectionViewLayoutAttributes *)attributes;

@end

@interface SYACyclePageViewLayout : NSObject

@property (nonatomic, assign) CGSize itemSize;

@property (nonatomic, assign) CGFloat itemSpacing;

@property (nonatomic, assign) UIEdgeInsets sectionInset;

@property (nonatomic, assign) SYACyclePageTransformLayoutType layoutType;

@property (nonatomic, assign) CGFloat minimumScale;

@property (nonatomic, assign) CGFloat minimumAlpha;

@property (nonatomic, assign) CGFloat maximumAngle;

@property (nonatomic, assign) BOOL isInfiniteLoop;

@property (nonatomic, assign) CGFloat rateOfChange;

@property (nonatomic, assign) BOOL adjustSpacingWhenScroling;

@property (nonatomic, assign) BOOL itemVerticalCenter;

@property (nonatomic, assign) BOOL itemHorizontalCenter;

// sectionInset
@property (nonatomic, assign, readonly) UIEdgeInsets onlyOneSectionInset;
@property (nonatomic, assign, readonly) UIEdgeInsets firstSectionInset;
@property (nonatomic, assign, readonly) UIEdgeInsets lastSectionInset;
@property (nonatomic, assign, readonly) UIEdgeInsets middleSectionInset;

@end

@interface SYACyclePageTransformLayout : UICollectionViewFlowLayout

@property (nonatomic, strong) SYACyclePageViewLayout *layout;

@property (nonatomic, weak) id<SYACyclePageTransformLayoutDelegate> delegate;

@end

NS_ASSUME_NONNULL_END

