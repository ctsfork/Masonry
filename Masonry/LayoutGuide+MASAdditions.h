//
//  LayoutGuide+MASAdditions.h
//  Masonry
//
//  Created by v on 2021/5/30.
//  Copyright © 2021 Jonas Budelmann. All rights reserved.
//

#import "MASUtilities.h"
#import "MASConstraintMaker.h"
#import "MASViewAttribute.h"

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(10.11), ios(9.0))
@interface MASLayoutGuide (MASAdditions)

@property (nonatomic, readonly) MASViewAttribute *mas_left;
@property (nonatomic, readonly) MASViewAttribute *mas_top;
@property (nonatomic, readonly) MASViewAttribute *mas_right;
@property (nonatomic, readonly) MASViewAttribute *mas_bottom;
@property (nonatomic, readonly) MASViewAttribute *mas_leading;
@property (nonatomic, readonly) MASViewAttribute *mas_trailing;
@property (nonatomic, readonly) MASViewAttribute *mas_width;
@property (nonatomic, readonly) MASViewAttribute *mas_height;
@property (nonatomic, readonly) MASViewAttribute *mas_centerX;
@property (nonatomic, readonly) MASViewAttribute *mas_centerY;

@property (nonatomic, copy, readonly) MASViewAttribute * (^mas_attribute)(NSLayoutAttribute attr);

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created MASConstraints
 */
- (NSArray *)mas_makeConstraints:(void (NS_NOESCAPE^)(id<MASLayoutConstraint> make))block;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)mas_updateConstraints:(void (NS_NOESCAPE^)(id<MASLayoutConstraint> make))block;

/**
 *  Creates a MASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  All constraints previously installed for the view will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)mas_remakeConstraints:(void (NS_NOESCAPE^)(id<MASLayoutConstraint> make))block;

@end

NS_ASSUME_NONNULL_END
