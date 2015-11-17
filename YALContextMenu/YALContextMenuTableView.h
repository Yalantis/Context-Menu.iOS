//
//  YALTableView.h
//  YALMenuAnimation
//
//  Created by Maksym Lazebnyi on 1/12/15.
//  Copyright (c) 2015 Yalantis. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, MenuItemsSide) {
    Left,
    Right
};

typedef NS_ENUM(NSInteger, MenuItemsAppearanceDirection) {
    FromTopToBottom,
    FromBottomToTop
};

@class YALContextMenuTableView;

@protocol YALContextMenuTableViewDelegate <NSObject>

@optional

/*!
 @abstract
 This method called when menu dismissed
 
 @param contextMenuTableView - object dismissed
 
 @param indexPath - indexPath of cell selected
*/
- (void)contextMenuTableView:(YALContextMenuTableView *)contextMenuTableView didDismissWithIndexPath:(NSIndexPath *)indexPath;

@end


@interface YALContextMenuTableView : UITableView

@property (nonatomic, weak) id <YALContextMenuTableViewDelegate> yalDelegate;

/*! @abstract animationDuration time for animation in seconds*/
@property (nonatomic) CGFloat animationDuration;

/*! The side of the screen to which menu items are related.
 When it set to 'Right' the first cell will be opened from right to left and selected cell will be closed from left to right.
 When it set to 'Left' the first cell will be opened from left to right and selected cell will be closed from right to left.
 Default - Right.*/
@property (nonatomic) MenuItemsSide menuItemsSide;

/*! Direction of menu item appearence. Default - FromTopToBottom.*/
@property (nonatomic) MenuItemsAppearanceDirection menuItemsAppearanceDirection;

/*!
 @abstract
 Call this method for initilization of the table view with datasource and delegate assigned.
 
 @param delegateDataSource - Add our class for delegate and dataSource methods here
 
 @return YALTableView object or nil
*/
- (instancetype)initWithTableViewDelegateDataSource:(id<UITableViewDelegate, UITableViewDataSource>)delegateDataSource;

/*!
 @abstract
 Use this method for correct presenration as [superview addSubview:MyYALTableView] will not present side menu properly.
 
 @param Superview to present your menu. If you are using a navigation controller it is better to use myViewController.navigationController.view as a suoerview.
 
 @param YES or NO weather you want appearance animated or not.
 */
- (void)showInView:(UIView *)superview withEdgeInsets:(UIEdgeInsets)edgeInsets animated:(BOOL)animated;

/*!
 @abstract
 Call this method to dismis your menuAnimated;
 
 @param indexPath of the cell selected (to be hidden the las one)
 */
- (void)dismisWithIndexPath:(NSIndexPath *)indexPath;

/*!
 @abstract
 Call this method before or during the device rotation animation
 */
- (void)updateAlongsideRotation;


@end
