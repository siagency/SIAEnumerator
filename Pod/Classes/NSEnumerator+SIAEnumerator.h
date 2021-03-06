//
//  NSEnumerator+SIAEnumerator.h
//  SIAEnumerator
//
//  Created by KUROSAKI Ryota on 2011/09/13.
//  Copyright (c) 2011-2018 SI Agency Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSEnumerator<ObjectType> (SIAEnumerator)

// find
- (nullable ObjectType)sia_find:(BOOL (^)(ObjectType obj))predicate;
- (nullable ObjectType)sia_find:(BOOL (^)(ObjectType obj))predicate ifNone:(nullable ObjectType)ifNone;
- (nullable ObjectType)sia_find:(BOOL (^)(ObjectType obj))predicate ifNoneBlock:(nullable ObjectType (^)(void))ifNoneBlock;

// filter
- (NSArray *)sia_filter:(BOOL (^)(ObjectType obj))predicate;
- (NSArray *)sia_findAll:(BOOL (^)(ObjectType obj))predicate __attribute__ ((deprecated));
- (NSArray *)sia_reject:(BOOL (^)(ObjectType obj))predicate;

// access all
- (void)sia_each:(void (^)(ObjectType obj))block;
- (NSArray *)sia_map:(id (^)(ObjectType obj))block;

// reduce
- (BOOL)sia_all:(BOOL (^)(ObjectType obj))predicate;
- (BOOL)sia_any:(BOOL (^)(ObjectType obj))predicate;
- (nullable ObjectType)sia_maxElement:(NSComparator)cmptr;
- (nullable ObjectType)sia_minElement:(NSComparator)cmptr;
- (nullable ObjectType)sia_max:(NSComparator)cmptr __attribute__ ((deprecated));
- (nullable ObjectType)sia_min:(NSComparator)cmptr __attribute__ ((deprecated));
- (nullable id)sia_reduce:(nullable id)initial combine:(nullable id (^)(id __nullable result, ObjectType obj))combine;
- (NSInteger)sia_reduceInteger:(NSInteger)initial combine:(NSInteger (^)(NSInteger result, ObjectType obj))combine;
- (NSUInteger)sia_reduceUInteger:(NSUInteger)initial combine:(NSUInteger (^)(NSUInteger result, ObjectType obj))combine;
- (float)sia_reduceFloat:(float)initial combine:(float (^)(float result, ObjectType obj))combine;
- (double)sia_reduceDouble:(double)initial combine:(double (^)(double result, ObjectType obj))combine;
- (CGFloat)sia_reduceCGFloat:(CGFloat)initial combine:(CGFloat (^)(CGFloat result, ObjectType obj))combine;

- (nullable id)sia_inject:(nullable id (^)(id __nullable result, ObjectType obj))injection __attribute__ ((deprecated));
- (nullable id)sia_inject:(nullable id (^)(id __nullable result, ObjectType obj))injection initialValue:(nullable id)initial __attribute__ ((deprecated));
- (NSInteger)sia_inject:(NSInteger (^)(NSInteger result, ObjectType obj))injection initialInteger:(NSInteger)initial __attribute__ ((deprecated));
- (NSUInteger)sia_inject:(NSUInteger (^)(NSUInteger result, ObjectType obj))injection initialUInteger:(NSUInteger)initial __attribute__ ((deprecated));
- (float)sia_inject:(float (^)(float result, ObjectType obj))injection initialFloat:(float)initial __attribute__ ((deprecated));
- (double)sia_inject:(double (^)(double result, ObjectType obj))injection initialDouble:(double)initial __attribute__ ((deprecated));
- (CGFloat)sia_inject:(CGFloat (^)(CGFloat result, ObjectType obj))injection initialCGFloat:(CGFloat)initial __attribute__ ((deprecated));

@end

@interface NSEnumerator<ObjectType> (SIAEnumerator2)

- (nullable ObjectType)sia_find2:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
- (nullable ObjectType)sia_find2:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate ifNone:(nullable ObjectType)ifNone;
- (nullable ObjectType)sia_find2:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate ifNoneBlock:(nullable ObjectType (^)(void))ifNoneBlock;
- (NSArray *)sia_filter2:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
- (NSArray *)sia_findAll2:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__ ((deprecated));
- (NSArray *)sia_reject2:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;

- (void)sia_each2:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;
- (BOOL)sia_all2:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
- (BOOL)sia_any2:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
- (NSArray *)sia_map2:(id (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;

- (nullable ObjectType)sia_maxElement2:(NSComparisonResult (^)(ObjectType obj1, ObjectType obj2, BOOL *stop))cmptr;
- (nullable ObjectType)sia_minElement2:(NSComparisonResult (^)(ObjectType obj1, ObjectType obj2, BOOL *stop))cmptr;
- (nullable ObjectType)sia_max2:(NSComparisonResult (^)(ObjectType obj1, ObjectType obj2, BOOL *stop))cmptr __attribute__ ((deprecated));
- (nullable ObjectType)sia_min2:(NSComparisonResult (^)(ObjectType obj1, ObjectType obj2, BOOL *stop))cmptr __attribute__ ((deprecated));

- (nullable id)sia_reduce2:(nullable id)initial combine:(nullable id (^)(id __nullable result, ObjectType obj, NSUInteger idx, BOOL *stop))combine;
- (NSInteger)sia_reduce2Integer:(NSInteger)initial combine:(NSInteger (^)(NSInteger result, ObjectType obj, NSUInteger idx, BOOL *stop))combine;
- (NSUInteger)sia_reduce2UInteger:(NSUInteger)initial combine:(NSUInteger (^)(NSUInteger result, ObjectType obj, NSUInteger idx, BOOL *stop))combine;
- (float)sia_reduce2Float:(float)initial combine:(float (^)(float result, ObjectType obj, NSUInteger idx, BOOL *stop))combine;
- (double)sia_reduce2Double:(double)initial combine:(double (^)(double result, ObjectType obj, NSUInteger idx, BOOL *stop))combine;
- (CGFloat)sia_reduce2CGFloat:(CGFloat)initial combine:(CGFloat (^)(CGFloat result, ObjectType obj, NSUInteger idx, BOOL *stop))combine;

- (nullable id)sia_inject2:(nullable id (^)(id __nullable result, ObjectType obj, NSUInteger idx, BOOL *stop))injection __attribute__ ((deprecated));
- (nullable id)sia_inject2:(nullable id (^)(id __nullable result, ObjectType obj, NSUInteger idx, BOOL *stop))injection initialValue:(nullable id)initial __attribute__ ((deprecated));
- (NSInteger)sia_inject2:(NSInteger (^)(NSInteger result, ObjectType obj, NSUInteger idx, BOOL *stop))injection initialInteger:(NSInteger)initial __attribute__ ((deprecated));
- (NSUInteger)sia_inject2:(NSUInteger (^)(NSUInteger result, ObjectType obj, NSUInteger idx, BOOL *stop))injection initialUInteger:(NSUInteger)initial __attribute__ ((deprecated));
- (float)sia_inject2:(float (^)(float result, ObjectType obj, NSUInteger idx, BOOL *stop))injection initialFloat:(float)initial __attribute__ ((deprecated));
- (double)sia_inject2:(double (^)(double result, ObjectType obj, NSUInteger idx, BOOL *stop))injection initialDouble:(double)initial __attribute__ ((deprecated));
- (CGFloat)sia_inject2:(CGFloat (^)(CGFloat result, ObjectType obj, NSUInteger idx, BOOL *stop))injection initialCGFloat:(CGFloat)initial __attribute__ ((deprecated));

@end

@interface SIAEnumerator : NSEnumerator

+ (SIAEnumerator *)enumeratorWithTraceBlock:(id (^)(NSInteger index, id previousObject))traceBlock;

@end

NS_ASSUME_NONNULL_END
