//
//  AppDelegate.m
//  Clone
//
//  Created by Deja Jackson on 6/11/15.
//  Copyright (c) 2015 Pixel by Pixel Games. All rights reserved.
//

#import "AppDelegate.h"
#import "Clone_Dist-Swift.h"
#import "CommentsTableViewController.h"
#import "PostDetailsViewController.h"
#import <Appirater.h>

NSString *const kCommentNotificationCategoryIdentifier = @"Comment";
NSString *const kLikeNotificationCategorIdentifier = @"Like";
NSString *const kViewLikedPostActionIdentifier = @"LikedPost";
NSString *const kViewCommentPostActionIdentifier = @"ViewComment";
NSString *const kReplyActionIdentifier = @"Reply";

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [application setStatusBarStyle:UIStatusBarStyleLightContent];
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
    [[UINavigationBar appearance] setBarTintColor:UIColorFromRGB(0x1c9ef1)];
    NSArray *iconsArray = @[@"Home", @"Search", @"Messages", @"Profile"];
    
    UIStoryboard *mainStoryboard = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
    UINavigationController *homeNav = [mainStoryboard instantiateViewControllerWithIdentifier:@"homenav"];
    UINavigationController *searchNav = [mainStoryboard instantiateViewControllerWithIdentifier:@"searchnav"];
    UINavigationController *messagesNav = [mainStoryboard instantiateViewControllerWithIdentifier:@"messagesnav"];
    // UINavigationController *notificationsNav = [mainStoryboard instantiateViewControllerWithIdentifier:@"notificationsnav"];
    UINavigationController *profileNav = [mainStoryboard instantiateViewControllerWithIdentifier:@"profilenav"];
    
    EYTabBar *tabBar = [[EYTabBar alloc] initWithIcons:iconsArray];
    tabBar.viewControllers = @[homeNav, searchNav, messagesNav, profileNav];
    tabBar.EYTabbarView.backgroundColor = [UIColor colorWithRed:67/255.0 green:74/255.0 blue:84/255.0 alpha:1.0];
    tabBar.selectedView.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0.3];
    
    self.window.rootViewController = tabBar;
    
    // Power Clone with Parse Local Datastore.
    [Parse enableLocalDatastore];
    
    // Enable crash reporting for Clone.
    [ParseCrashReporting enable];
    
    // Enable data sharing between the parent app and its extensions.
    [Parse enableDataSharingWithApplicationGroupIdentifier:@"group.com.pixelbypixel.Clone"];
    
    // Initialize Parse.
    [Parse setApplicationId:@"zXsU51Bh1AwneejkVIYUMRZzI0MQXIJLy1IM0LOh"
                  clientKey:@"hvDPq4a89vLnKYwkZLBMytS3M2R8qsLiOFpxFC3L"];
    [PFFacebookUtils initializeFacebookWithApplicationLaunchOptions:launchOptions];
    [PFTwitterUtils initializeWithConsumerKey:@"9htkSP2t9WyflWAlLPSKJQLZ8"
                               consumerSecret:@"Jd0F4ecZHTQoGZD7cPNPX9MxsF3S9qe8glsRmyb17SIZtMyr3X"];
    
    // [Optional] Track statistics around application opens.
    [PFAnalytics trackAppOpenedWithLaunchOptions:launchOptions];
    
    [Appirater setAppId:@"964396148"];
    [Appirater setDaysUntilPrompt:7];
    [Appirater setUsesUntilPrompt:20];
    [Appirater setTimeBeforeReminding:3];
    [Appirater setDebug:NO];
    
    UIMutableUserNotificationAction *viewLikedPostAction = [[UIMutableUserNotificationAction alloc] init];
    viewLikedPostAction.activationMode = UIUserNotificationActivationModeBackground;
    viewLikedPostAction.title = NSLocalizedString(@"View Post", @"view");
    viewLikedPostAction.identifier = kViewLikedPostActionIdentifier;
    viewLikedPostAction.destructive = NO;
    viewLikedPostAction.authenticationRequired = NO;
    
    UIMutableUserNotificationAction *viewCommentPostAction = [[UIMutableUserNotificationAction alloc] init];
    viewCommentPostAction.activationMode = UIUserNotificationActivationModeBackground;
    viewCommentPostAction.title = NSLocalizedString(@"View Post", @"view");
    viewCommentPostAction.identifier = kViewCommentPostActionIdentifier;
    viewCommentPostAction.destructive = NO;
    viewCommentPostAction.authenticationRequired = NO;
    
    UIMutableUserNotificationAction *replyToCommentAction = [[UIMutableUserNotificationAction alloc] init];
    replyToCommentAction.activationMode = UIUserNotificationActivationModeBackground;
    replyToCommentAction.title = NSLocalizedString(@"Reply", @"reply");
    replyToCommentAction.identifier = kReplyActionIdentifier;
    replyToCommentAction.destructive = NO;
    replyToCommentAction.authenticationRequired = YES;
    
    UIMutableUserNotificationCategory *likeNotificationCategory = [[UIMutableUserNotificationCategory alloc] init];
    likeNotificationCategory.identifier = kLikeNotificationCategorIdentifier;
    [likeNotificationCategory setActions:@[viewLikedPostAction] forContext:UIUserNotificationActionContextDefault];
    
    UIMutableUserNotificationCategory *commentNotificationCategory = [[UIMutableUserNotificationCategory alloc] init];
    commentNotificationCategory.identifier = kCommentNotificationCategoryIdentifier;
    [commentNotificationCategory setActions:@[viewCommentPostAction, replyToCommentAction] forContext:UIUserNotificationActionContextDefault];
    
    if ([application respondsToSelector:@selector(registerUserNotificationSettings:)]) {
        UIUserNotificationType userNotificationTypes = (UIUserNotificationTypeAlert |
                                                        UIUserNotificationTypeBadge |
                                                        UIUserNotificationTypeSound);
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:userNotificationTypes
                                                                                 categories:[NSSet setWithObjects:likeNotificationCategory, commentNotificationCategory, nil]];
        [application registerUserNotificationSettings:settings];
        [application registerForRemoteNotifications];
    } else {
        [application registerForRemoteNotificationTypes:UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound];
    }
    
    return [[FBSDKApplicationDelegate sharedInstance] application:application
                                    didFinishLaunchingWithOptions:launchOptions];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [[PFInstallation currentInstallation] setDeviceTokenFromData:deviceToken];
    [[PFInstallation currentInstallation] saveInBackground];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    [PFPush handlePush:userInfo];
}

- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo completionHandler:(void (^)())completionHandler {
    if ([identifier isEqualToString:kReplyActionIdentifier]) {
        if ([[PFInstallation currentInstallation] badge] > 0) {
            [[PFInstallation currentInstallation] setBadge:[[PFInstallation currentInstallation] badge] - 1];
            [[PFInstallation currentInstallation] saveInBackground];
        }
        CommentsTableViewController *commentsController = [[CommentsTableViewController alloc] init];
        commentsController.postObject = [userInfo objectForKey:@"post"];
        commentsController.isModal = YES;
        commentsController.textView.text = [NSString stringWithFormat:@"@%@", [[[userInfo objectForKey:@"post"] objectForKey:@"user"] objectForKey:@"username"]];
        [self.window.rootViewController presentViewController:commentsController animated:YES completion:nil];
    } else if ([identifier isEqualToString:kViewLikedPostActionIdentifier]) {
        if ([[PFInstallation currentInstallation] badge] > 0) {
            [[PFInstallation currentInstallation] setBadge:[[PFInstallation currentInstallation] badge] - 1];
            [[PFInstallation currentInstallation] saveInBackground];
        }
        PostDetailsViewController *postDetails = [[PostDetailsViewController alloc] init];
        postDetails.isModal = YES;
        postDetails.post = [userInfo objectForKey:@"post"];
        [self.window.rootViewController presentViewController:postDetails animated:YES completion:nil];
    } else if ([identifier isEqualToString:kViewCommentPostActionIdentifier]) {
        if ([[PFInstallation currentInstallation] badge] > 0) {
            [[PFInstallation currentInstallation] setBadge:[[PFInstallation currentInstallation] badge] - 1];
            [[PFInstallation currentInstallation] saveInBackground];
        }
        PostDetailsViewController *postDetails = [[PostDetailsViewController alloc] init];
        postDetails.isModal = YES;
        postDetails.post = [userInfo objectForKey:@"post"];
        [self.window.rootViewController presentViewController:postDetails animated:YES completion:nil];
    }
    
    if (completionHandler) {
        completionHandler();
    }
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    [application setStatusBarStyle:UIStatusBarStyleLightContent];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    [FBSDKAppEvents activateApp];
    [application setStatusBarStyle:UIStatusBarStyleLightContent];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    // Called when the application should open another application.
    return [[FBSDKApplicationDelegate sharedInstance] application:application
                                                          openURL:url
                                                sourceApplication:sourceApplication
                                                       annotation:annotation];
}

@end
