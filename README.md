# Context-Menu.iOS

#### You can easily add awesome animated context menu to  your app.
Made in [![Yalantis](https://raw.githubusercontent.com/Yalantis/FoldingTabBar.iOS/master/Example/Example/Resources/Images/badge_orage_shadow.png)](http://yalantis.com/?utm_source=github)

Check this [project on dribbble] (https://dribbble.com/shots/1785274-Menu-Animation-for-Additional-Functions?list=users&offset=17)

Check this [project on Behance] (https://www.behance.net/gallery/20411445/Mobile-Animations-Interactions)  

![ContextMenu](https://d13yacurqjgara.cloudfront.net/users/125056/screenshots/1785274/99miles-profile-light_1-1-4.gif)

####[CocoaPods](http://cocoapods.org)
```ruby
pod 'ContextMenu.iOS', '~> 1.0.0'
```

####Usage

You are welcome to see the sample of the project for fully operating sample in the Example folder.

  * Add folder YALContextMenu to your project.
  * `#import “YALContextMenuTableView.h”` to your view controller
  * Create custom UITableViewCell with UIView property for rotation animation and UIView property for fade out animation.
  * Your custom cell should implement YALContextMenuCell protocol

```objective-c
@protocol YALContextMenuCell <NSObject>

- (UIView *)animatedIcon;
- (UIView *)animatedContent;

@end
```

  * Use the following code sample to start menu 

```objective-c
- (IBAction)presentMenuButtonTapped:(UIBarButtonItem *)sender {
    // init YALContextMenuTableView tableView
    if (!self.contextMenuTableView) {
        self.contextMenuTableView = [[YALContextMenuTableView alloc]initWithTableViewDelegateDataSource:self];
        self.contextMenuTableView.animationDuration = 0.15;
        //optional - implement custom YALContextMenuTableView custom protocol
        self.contextMenuTableView.yalDelegate = self;
        
        //register nib
        UINib *cellNib = [UINib nibWithNibName:@"ContextMenuCell" bundle:nil];
        [self.contextMenuTableView registerNib:cellNib forCellReuseIdentifier:@"contextMenuCellReuseId"];
    }

    // it is better to use this method only for proper animation
    [self.contextMenuTableView showInView:self.navigationController.view withEdgeInsets:UIEdgeInsetsZero animated:YES];
}
```

  * Use default UITableViewDataSource methods for additional set up and customisation of the cell.
  * Сall `updateAlongsideRotation` method before the rotation animation started and `reloadData` method after rotation animation finished or in UIViewControllerTransitionCoordinator's `animateAlongsideTransition` block for proper rotation animation.
 

```objective-c
 - (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation{
    //should be called after rotation animation completed
    [self.contextMenuTableView reloadData];
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration {
    [super willRotateToInterfaceOrientation:toInterfaceOrientation duration:duration];
    
    [self.contextMenuTableView updateAlongsideRotation];
}

- (void)viewWillTransitionToSize:(CGSize)size
       withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    
    [super viewWillTransitionToSize:size withTransitionCoordinator:coordinator];
    
    
    [coordinator animateAlongsideTransition:nil completion:^(id<UIViewControllerTransitionCoordinatorContext> context) {
        //should be called after rotation animation completed
        [self.contextMenuTableView reloadData];
    }];
    [self.contextMenuTableView updateAlongsideRotation];
    
}
```
 
### Customisation

To customise cell set up your custom drawables in the animated icon. Actually the cell design and layout is completely at your choice.

animationDuration is to be used for animation speed in seconds.

### Compatibility

iOS 7,
iOS 8

#### Version: 1.0

### License

    Copyright 2015, Yalantis

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
  
