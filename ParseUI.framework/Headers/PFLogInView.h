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

#import <ParseUI/ParseUIConstants.h>

<<<<<<< HEAD
NS_ASSUME_NONNULL_BEGIN

/**
=======
PFUI_ASSUME_NONNULL_BEGIN

/*!
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944
 `PFLogInFields` bitmask specifies the log in elements which are enabled in the view.

 @see PFLogInViewController
 @see PFLogInView
 */
typedef NS_OPTIONS(NSInteger, PFLogInFields) {
<<<<<<< HEAD
    /** No fields. */
    PFLogInFieldsNone = 0,
    /** Username and password fields. */
    PFLogInFieldsUsernameAndPassword = 1 << 0,
    /** Forgot password button. */
    PFLogInFieldsPasswordForgotten = 1 << 1,
    /** Login button. */
    PFLogInFieldsLogInButton = 1 << 2,
    /** Button to login with Facebook. */
    PFLogInFieldsFacebook = 1 << 3,
    /** Button to login with Twitter. */
    PFLogInFieldsTwitter = 1 << 4,
    /** Signup Button. */
    PFLogInFieldsSignUpButton = 1 << 5,
    /** Dismiss Button. */
    PFLogInFieldsDismissButton = 1 << 6,

    /** Default value. Combines Username, Password, Login, Signup, Forgot Password and Dismiss buttons. */
=======
    /*! No fields. */
    PFLogInFieldsNone = 0,
    /*! Username and password fields. */
    PFLogInFieldsUsernameAndPassword = 1 << 0,
    /*! Forgot password button. */
    PFLogInFieldsPasswordForgotten = 1 << 1,
    /*! Login button. */
    PFLogInFieldsLogInButton = 1 << 2,
    /*! Button to login with Facebook. */
    PFLogInFieldsFacebook = 1 << 3,
    /*! Button to login with Twitter. */
    PFLogInFieldsTwitter = 1 << 4,
    /*! Signup Button. */
    PFLogInFieldsSignUpButton = 1 << 5,
    /*! Dismiss Button. */
    PFLogInFieldsDismissButton = 1 << 6,

    /*! Default value. Combines Username, Password, Login, Signup, Forgot Password and Dismiss buttons. */
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944
    PFLogInFieldsDefault = (PFLogInFieldsUsernameAndPassword |
                            PFLogInFieldsLogInButton |
                            PFLogInFieldsSignUpButton |
                            PFLogInFieldsPasswordForgotten |
                            PFLogInFieldsDismissButton)
};

<<<<<<< HEAD
/**
 `PFLoginFields`'s accessibility label identifiers
 
 @see PFLogInView
 */
extern NSString *const PFLogInViewUsernameFieldAccessibilityIdentifier;
extern NSString *const PFLogInViewPasswordFieldAccessibilityIdentifier;
extern NSString *const PFLogInViewLogInButtonAccessibilityIdentifier;
extern NSString *const PFLogInViewSignUpButtonAccessibilityIdentifier;
extern NSString *const PFLogInViewPasswordForgottenButtonAccessibilityIdentifier;
extern NSString *const PFLogInViewTwitterButtonAccessibilityIdentifier;
extern NSString *const PFLogInViewFacebookButtonAccessibilityIdentifier;
extern NSString *const PFLogInViewDismissButtonAccessibilityIdentifier;

@class PFTextField;

/**
 The `PFLogInView` class provides a standard log in interface for authenticating a `PFUser`.
=======
@class PFTextField;

/*!
 The `PFLogInView` class provides a standard log in interface for authenticating a <PFUser>.
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944
 */
@interface PFLogInView : UIScrollView

///--------------------------------------
/// @name Creating Log In View
///--------------------------------------

<<<<<<< HEAD
/**
 Initializes the view with the specified log in elements.

 @param fields A bitmask specifying the log in elements which are enabled in the view

 @return An initialized `PFLogInView` object or `nil` if the object couldn't be created.
=======
/*!
 @abstract Initializes the view with the specified log in elements.

 @param fields A bitmask specifying the log in elements which are enabled in the view

 @returns An initialized `PFLogInView` object or `nil` if the object couldn't be created.
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944

 @see PFLogInFields
 */
- (instancetype)initWithFields:(PFLogInFields)fields;

<<<<<<< HEAD
/**
 The view controller that will present this view.

 Used to lay out elements correctly when the presenting view controller has translucent elements.
 */
@property (nullable, nonatomic, weak) UIViewController *presentingViewController;
=======
/*!
 @abstract The view controller that will present this view.

 @discussion Used to lay out elements correctly when the presenting view controller has translucent elements.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, weak) UIViewController *presentingViewController;
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944

///--------------------------------------
/// @name Customizing the Logo
///--------------------------------------

/// The logo. By default, it is the Parse logo.
<<<<<<< HEAD
@property (nullable, nonatomic, strong) UIView *logo;
=======
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong) UIView *logo;
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944

///--------------------------------------
/// @name Configure Username Behaviour
///--------------------------------------

<<<<<<< HEAD
/**
 If email should be used to log in, instead of username

 By default, this is set to `NO`.
=======
/*!
 @abstract If email should be used to log in, instead of username

 @discussion By default, this is set to `NO`.
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944
 */
@property (nonatomic, assign) BOOL emailAsUsername;

///--------------------------------------
/// @name Log In Elements
///--------------------------------------

<<<<<<< HEAD
/**
 The bitmask which specifies the enabled log in elements in the view.
 */
@property (nonatomic, assign, readonly) PFLogInFields fields;

/**
 The username text field. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) PFTextField *usernameField;

/**
 The password text field. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) PFTextField *passwordField;

/**
 The password forgotten button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *passwordForgottenButton;

/**
 The log in button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *logInButton;

/**
 The Facebook button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *facebookButton;

/**
 The Twitter button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *twitterButton;

/**
 The sign up button. It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *signUpButton;

/**
 It is `nil` if the element is not enabled.
 */
@property (nullable, nonatomic, strong, readonly) UIButton *dismissButton;

/**
 The facebook/twitter login label.

 @deprecated This property is deprecated and will always be nil.
 */
@property (nullable, nonatomic, strong, readonly) UILabel *externalLogInLabel __attribute__(PARSE_UI_DEPRECATED("This property is deprecated and will always be nil."));

/**
 The sign up label.

 @deprecated This property is deprecated and will always be nil.
 */
@property (nullable, nonatomic, strong, readonly) UILabel *signUpLabel __attribute__(PARSE_UI_DEPRECATED("This property is deprecated and will always be nil."));

@end

NS_ASSUME_NONNULL_END
=======
/*!
 @abstract The bitmask which specifies the enabled log in elements in the view.
 */
@property (nonatomic, assign, readonly) PFLogInFields fields;

/*!
 @abstract The username text field. It is `nil` if the element is not enabled.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong, readonly) PFTextField *usernameField;

/*!
 @abstract The password text field. It is `nil` if the element is not enabled.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong, readonly) PFTextField *passwordField;

/*!
 @abstract The password forgotten button. It is `nil` if the element is not enabled.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong, readonly) UIButton *passwordForgottenButton;

/*!
 @abstract The log in button. It is `nil` if the element is not enabled.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong, readonly) UIButton *logInButton;

/*!
 @abstract The Facebook button. It is `nil` if the element is not enabled.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong, readonly) UIButton *facebookButton;

/*!
 @abstract The Twitter button. It is `nil` if the element is not enabled.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong, readonly) UIButton *twitterButton;

/*!
 @abstract The sign up button. It is `nil` if the element is not enabled.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong, readonly) UIButton *signUpButton;

/*!
 @abstract It is `nil` if the element is not enabled.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong, readonly) UIButton *dismissButton;

/*!
 @abstract The facebook/twitter login label.

 @deprecated This property is deprecated and will always be nil.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong, readonly) UILabel *externalLogInLabel __attribute__(PARSE_UI_DEPRECATED("This property is deprecated and will always be nil."));

/*!
 @abstract The sign up label.

 @deprecated This property is deprecated and will always be nil.
 */
@property (PFUI_NULLABLE_PROPERTY nonatomic, strong, readonly) UILabel *signUpLabel __attribute__(PARSE_UI_DEPRECATED("This property is deprecated and will always be nil."));

@end

PFUI_ASSUME_NONNULL_END
>>>>>>> 2a3cbcc766224b91151fa0aada91788572b24944
