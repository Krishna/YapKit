//
//  YapPagingCollectionView.h
//  yap-iphone
//
//  Created by Trevor Stout on 4/16/13.
//  Copyright (c) 2013 Yap.tv, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YapPagingCollectionView;

@protocol YapPagingCollectionViewDelegate;
@protocol YapHorizontalImageCollectionViewDataSource;

@interface YapPagingCollectionView : UIView <UICollectionViewDelegate, UICollectionViewDataSource, UIGestureRecognizerDelegate>

@property (nonatomic, assign) id <YapPagingCollectionViewDelegate> delegate;
@property (nonatomic, assign) id <YapHorizontalImageCollectionViewDataSource> dataSource;

@property (nonatomic, assign) CGFloat pageWidth;
@property (nonatomic, readonly) NSUInteger page;
@property (nonatomic, readonly) NSUInteger maxPage;

- (void)setPage:(NSUInteger)page animated:(BOOL)animated;
- (NSUInteger)pageForItemAtIndex:(NSUInteger)index;
@property (nonatomic, assign) CGSize itemSize; // default 192 x 64
@property (nonatomic, assign) UIEdgeInsets contentInset;
@property (nonatomic, assign) CGFloat interitemSpacing;
@property (nonatomic, assign) BOOL scrollEnabled;

- (void)setImageHidden:(BOOL)hidden atIndex:(NSInteger)index;
- (NSArray *)visibleCells;
- (void)setAllImagesVisible;
- (CGRect)rectForImageAtIndex:(NSUInteger)index inView:(UIView *)view;
- (void)registerClass:(Class)cellClass forCellWithReuseIdentifier:(NSString *)identifier;
- (id)dequeueReusableCellWithReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath*)indexPath;
- (void)reloadData;
- (BOOL)isImageHiddenAtIndex:(NSInteger)index;
- (NSIndexPath *)indexPathForCell:(UICollectionViewCell *)cell;

@end

// delegate
@protocol YapPagingCollectionViewDelegate <NSObject>

@optional
- (void)horizontalImageCollectionViewDidEndPanning:(YapPagingCollectionView *)horizontalImageCollectionView willPageToPage:(NSInteger)page;
- (void)horizontalImageCollectionView:(YapPagingCollectionView *)horizontalImageCollectionView didPageToPage:(NSInteger)page;
- (void)horizontalImageCollectionViewDidScroll:(YapPagingCollectionView *)horizontalImageCollectionView;
- (void)horizontalImageCollection:(YapPagingCollectionView *)horizontalImageCollectionView didTapImageAtIndex:(NSUInteger)index;
@end

// data source
@protocol YapHorizontalImageCollectionViewDataSource <NSObject>

- (NSInteger)numberOfItemsInHorizontalImageCollection:(YapPagingCollectionView *)horizontalImageCollectionView;
- (UICollectionViewCell *)collectionView:(YapPagingCollectionView *)collectionView itemAtIndexPath:(NSIndexPath *)indexPath;

@end
