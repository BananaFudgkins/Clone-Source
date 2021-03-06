
//
//  ProfilePageViewController.h
//  Clone
//
//  Created by Deja Jackson on 6/13/15.
//  Copyright (c) 2015 Pixel by Pixel Games. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Parse/Parse.h>
#import <LGRefreshView.h>

#import "UIScrollView+EmptyDataSet.h"
#import "SKPSMTPMessage.h"

@interface ProfilePageViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, DZNEmptyDataSetDelegate, DZNEmptyDataSetSource, LGRefreshViewDelegate, SKPSMTPMessageDelegate>

@property (strong, nonatomic) IBOutlet UIImageView *profilepicImageView;
@property (strong, nonatomic) IBOutlet UILabel *usernameLabel;
@property (strong, nonatomic) IBOutlet UILabel *realnameLabel;
@property (strong, nonatomic) IBOutlet UITextView *bioTextView;
@property (strong, nonatomic) IBOutlet UITableView *postsTableView;
@property (strong, nonatomic) IBOutlet UIScrollView *profileScrollView;
@property (strong, nonatomic) LGRefreshView *refreshView;

@end
