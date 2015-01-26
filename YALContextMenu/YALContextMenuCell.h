//
//  YALContextMenuCell.h
//  ContextMenu
//
//  Created by Maksym Lazebnyi on 1/21/15.
//  Copyright (c) 2015 Yalantis. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol YALContextMenuCell <NSObject>

/*!
 @abstract
 Following methods called for cell when animation to be processed
 */
- (UIView *)animatedIcon;
- (UIView *)animatedContent;

@end
