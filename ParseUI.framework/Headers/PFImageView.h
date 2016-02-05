/*
 *  Copyright (c) 2014, Parse, LLC. All rights reserved.
 *
 *  You are hereby granted a non-exclusive, worldwide, royalty-free license to use,
 *  copy, modify, and distribute this software in source code or binary form for use
 *  in connection with the web services and APIs provided by Parse.
 *
 *  As with any software that integrates with the Parse platform, your use of
 *  this software is subject to the Parse Terms of Service
 *  [https://www.parse.com/about/terms]. This copyright notice shall be
 *  included in all copies or substantial portions of the software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 *  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 *  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 *  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 *  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#import <UIKit/UIKit.h>

<<<<<<< HEAD
#import <Parse/PFConstants.h>

#import <ParseUI/ParseUIConstants.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^PFImageViewImageResultBlock)(UIImage *__nullable image,  NSError *__nullable error);

@class BFTask<__covariant BFGenericType>;
@class PFFile;

/**
=======
#import <ParseUI/ParseUIConstants.h>

PFUI_ASSUME_NONNULL_BEGIN

typedef void(^PFImageViewImageResultBlock)(UIImage *PFUI_NULLABLE_S image,  NSError *PFUI_NULLABLE_S error);

@class BFTask;
@class PFFile;

/*!
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944
 An image view that downloads and displays remote image stored on Parse's server.
 */
@interface PFImageView : UIImageView

<<<<<<< HEAD
/**
 The remote file on Parse's server that stores the image.

 @warning Note that the download does not start until `-loadInBackground:` is called.
 */
@property (nullable, nonatomic, strong) PFFile *file;

/**
 Initiate downloading of the remote image.

 Once the download completes, the remote image will be displayed.

 @return The task, that encapsulates the work being done.
 */
- (BFTask<UIImage *> *)loadInBackground;

/**
 Initiate downloading of the remote image.

 Once the download completes, the remote image will be displayed.

 @param completion the completion block.
 */
- (void)loadInBackground:(nullable PFImageViewImageResultBlock)completion;

/**
 Initiate downloading of the remote image.
 
 Once the download completes, the remote image will be displayed.
=======
/*!
 @abstract The remote file on Parse's server that stores the image.

 @warning Note that the download does not start until <loadInBackground:> is called.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong) PFFile *file;

/*!
 @abstract Initiate downloading of the remote image.

 @discussion Once the download completes, the remote image will be displayed.

 @returns The task, that encapsulates the work being done.
 */
- (BFTask *)loadInBackground;

/*!
 @abstract Initiate downloading of the remote image.

 @discussion Once the download completes, the remote image will be displayed.

 @param completion the completion block.
 */
- (void)loadInBackground:(PFUI_NULLABLE PFImageViewImageResultBlock)completion;

/*!
 @abstract Initiate downloading of the remote image.
 
 @discussion Once the download completes, the remote image will be displayed.
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944
 
 @param completion the completion block.
 @param progressBlock called with the download progress as the image is being downloaded. 
 Will be called with a value of 100 before the completion block is called.
 */
<<<<<<< HEAD
- (void)loadInBackground:(nullable PFImageViewImageResultBlock)completion
           progressBlock:(nullable void (^)(int percentDone))progressBlock;

@end

NS_ASSUME_NONNULL_END
=======
- (void)loadInBackground:(PFUI_NULLABLE PFImageViewImageResultBlock)completion
           progressBlock:(PFUI_NULLABLE void (^)(int percentDone))progressBlock;

@end

PFUI_ASSUME_NONNULL_END
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944
