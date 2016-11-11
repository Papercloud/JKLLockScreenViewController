//
//  JKLLockScreenViewController.h
//  JKLib
//
//  @date   2015. 03. 25.
//  @author Choi JoongKwan
//  @email  joongkwan.choi@gmail.com
//  @brief  Lock Screen View Controller class
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, LockScreenMode) {
    LockScreenModeNormal = 0,       // [일반 모드]
    LockScreenModeNew,              // [신규 모드]
    LockScreenModeChange,           // [변경 모드]
    LockScreenModeVerification,     // [확인 모드]
};

typedef NS_ENUM(NSInteger, LockScreenState) {
    LockScreenStateNormal = 0,
    LockScreenStateNew,
    LockScreenStateChange,
    LockScreenStateError,
    LockScreenStateConfirm,
};

typedef NS_ENUM(NSInteger, LockScreenError) {
    LockScreenErrorInvalid = 0,
    LockScreenErrorConfirmCodeDidNotMatch,
};

@protocol JKLLockScreenViewControllerDelegate;
@protocol JKLLockScreenViewControllerDataSource;

@interface JKLLockScreenViewController : UIViewController

@property (nonatomic, unsafe_unretained) LockScreenMode lockScreenMode;
@property (nonatomic, weak) IBOutlet id<JKLLockScreenViewControllerDelegate> delegate;
@property (nonatomic, weak) IBOutlet id<JKLLockScreenViewControllerDataSource> dataSource;

@property (weak, nonatomic) IBOutlet UIButton * deleteButton;
@property (nonatomic, weak) IBOutlet UIButton * cancelButton;


/**
 *  Tint color for the buttons
 */
@property (nonatomic, weak) UIColor *tintColor;

@end

@protocol JKLLockScreenViewControllerDelegate <NSObject>
@optional
- (void)unlockWasSuccessfulLockScreenViewController:(JKLLockScreenViewController *)lockScreenViewController pincode:(NSString *)pincode;    // support for number
- (void)unlockWasSuccessfulLockScreenViewController:(JKLLockScreenViewController *)lockScreenViewController;                                // support for touch id
- (void)unlockWasCancelledLockScreenViewController:(JKLLockScreenViewController *)lockScreenViewController;
- (void)unlockWasDeletedLockScreenViewController:(JKLLockScreenViewController *)lockScreenViewController;
- (void)unlockWasFailureLockScreenViewController:(JKLLockScreenViewController *)lockScreenViewController;
@end

@protocol JKLLockScreenViewControllerDataSource <NSObject>
@required
- (BOOL)lockScreenViewController:(JKLLockScreenViewController *)lockScreenViewController pincode:(NSString *)pincode;
@optional
- (BOOL)allowTouchIDLockScreenViewController:(JKLLockScreenViewController *)lockScreenViewController;
- (NSString *)titleForState:(LockScreenState)state;
- (NSString *)subtitleForError:(LockScreenError)error;
- (NSString *)touchIDReasonDescription;
@end
