// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: struct_lite.proto
// Protobuf C++ Version: 5.26.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_struct_5flite_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_struct_5flite_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION != 5026001
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/message_lite.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/map.h"  // IWYU pragma: export
#include "google/protobuf/map_field_lite.h"
#include "google/protobuf/generated_enum_util.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_struct_5flite_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_struct_5flite_2eproto {
  static const ::uint32_t offsets[];
};
namespace google {
namespace protobuf {
class ListValue;
struct ListValueDefaultTypeInternal;
extern ListValueDefaultTypeInternal _ListValue_default_instance_;
class Struct;
struct StructDefaultTypeInternal;
extern StructDefaultTypeInternal _Struct_default_instance_;
class Value;
struct ValueDefaultTypeInternal;
extern ValueDefaultTypeInternal _Value_default_instance_;
}  // namespace protobuf
}  // namespace google

namespace google {
namespace protobuf {
enum NullValue : int {
  NULL_VALUE = 0,
  NullValue_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  NullValue_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool NullValue_IsValid(int value);
extern const uint32_t NullValue_internal_data_[];
constexpr NullValue NullValue_MIN = static_cast<NullValue>(0);
constexpr NullValue NullValue_MAX = static_cast<NullValue>(0);
constexpr int NullValue_ARRAYSIZE = 0 + 1;
const std::string& NullValue_Name(NullValue value);
template <typename T>
const std::string& NullValue_Name(T value) {
  static_assert(std::is_same<T, NullValue>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to NullValue_Name().");
  return NullValue_Name(static_cast<NullValue>(value));
}
bool NullValue_Parse(absl::string_view name, NullValue* value);

// ===================================================================


// -------------------------------------------------------------------

class ListValue final : public ::google::protobuf::MessageLite
/* @@protoc_insertion_point(class_definition:google.protobuf.ListValue) */ {
 public:
  inline ListValue() : ListValue(nullptr) {}
  ~ListValue() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR ListValue(
      ::google::protobuf::internal::ConstantInitialized);

  inline ListValue(const ListValue& from) : ListValue(nullptr, from) {}
  inline ListValue(ListValue&& from) noexcept
      : ListValue(nullptr, std::move(from)) {}
  inline ListValue& operator=(const ListValue& from) {
    CopyFrom(from);
    return *this;
  }
  inline ListValue& operator=(ListValue&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const std::string& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<std::string>(::google::protobuf::internal::GetEmptyString);
  }
  inline std::string* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<std::string>();
  }

  static const ListValue& default_instance() {
    return *internal_default_instance();
  }
  static inline const ListValue* internal_default_instance() {
    return reinterpret_cast<const ListValue*>(
        &_ListValue_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 3;
  friend void swap(ListValue& a, ListValue& b) { a.Swap(&b); }
  inline void Swap(ListValue* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ListValue* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ListValue* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::MessageLite::DefaultConstruct<ListValue>(arena);
  }
  void CheckTypeAndMergeFrom(
      const ::google::protobuf::MessageLite& from) final;
  void CopyFrom(const ListValue& from);
  void MergeFrom(const ListValue& from);
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(ListValue* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "google.protobuf.ListValue"; }

 protected:
  explicit ListValue(::google::protobuf::Arena* arena);
  ListValue(::google::protobuf::Arena* arena, const ListValue& from);
  ListValue(::google::protobuf::Arena* arena, ListValue&& from) noexcept
      : ListValue(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kValuesFieldNumber = 1,
  };
  // repeated .google.protobuf.Value values = 1;
  int values_size() const;
  private:
  int _internal_values_size() const;

  public:
  void clear_values() ;
  ::google::protobuf::Value* mutable_values(int index);
  ::google::protobuf::RepeatedPtrField<::google::protobuf::Value>* mutable_values();

  private:
  const ::google::protobuf::RepeatedPtrField<::google::protobuf::Value>& _internal_values() const;
  ::google::protobuf::RepeatedPtrField<::google::protobuf::Value>* _internal_mutable_values();
  public:
  const ::google::protobuf::Value& values(int index) const;
  ::google::protobuf::Value* add_values();
  const ::google::protobuf::RepeatedPtrField<::google::protobuf::Value>& values() const;
  // @@protoc_insertion_point(class_scope:google.protobuf.ListValue)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 1,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::RepeatedPtrField< ::google::protobuf::Value > values_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_struct_5flite_2eproto;
};
// -------------------------------------------------------------------

class Struct final : public ::google::protobuf::MessageLite
/* @@protoc_insertion_point(class_definition:google.protobuf.Struct) */ {
 public:
  inline Struct() : Struct(nullptr) {}
  ~Struct() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Struct(
      ::google::protobuf::internal::ConstantInitialized);

  inline Struct(const Struct& from) : Struct(nullptr, from) {}
  inline Struct(Struct&& from) noexcept
      : Struct(nullptr, std::move(from)) {}
  inline Struct& operator=(const Struct& from) {
    CopyFrom(from);
    return *this;
  }
  inline Struct& operator=(Struct&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const std::string& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<std::string>(::google::protobuf::internal::GetEmptyString);
  }
  inline std::string* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<std::string>();
  }

  static const Struct& default_instance() {
    return *internal_default_instance();
  }
  static inline const Struct* internal_default_instance() {
    return reinterpret_cast<const Struct*>(
        &_Struct_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(Struct& a, Struct& b) { a.Swap(&b); }
  inline void Swap(Struct* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Struct* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Struct* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::MessageLite::DefaultConstruct<Struct>(arena);
  }
  void CheckTypeAndMergeFrom(
      const ::google::protobuf::MessageLite& from) final;
  void CopyFrom(const Struct& from);
  void MergeFrom(const Struct& from);
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Struct* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "google.protobuf.Struct"; }

 protected:
  explicit Struct(::google::protobuf::Arena* arena);
  Struct(::google::protobuf::Arena* arena, const Struct& from);
  Struct(::google::protobuf::Arena* arena, Struct&& from) noexcept
      : Struct(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kFieldsFieldNumber = 1,
  };
  // map<string, .google.protobuf.Value> fields = 1;
  int fields_size() const;
  private:
  int _internal_fields_size() const;

  public:
  void clear_fields() ;
  const ::google::protobuf::Map<std::string, ::google::protobuf::Value>& fields() const;
  ::google::protobuf::Map<std::string, ::google::protobuf::Value>* mutable_fields();

  private:
  const ::google::protobuf::Map<std::string, ::google::protobuf::Value>& _internal_fields() const;
  ::google::protobuf::Map<std::string, ::google::protobuf::Value>* _internal_mutable_fields();

  public:
  // @@protoc_insertion_point(class_scope:google.protobuf.Struct)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 2,
      37, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::MapFieldLite<std::string, ::google::protobuf::Value> fields_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_struct_5flite_2eproto;
};
// -------------------------------------------------------------------

// -------------------------------------------------------------------

class Value final : public ::google::protobuf::MessageLite
/* @@protoc_insertion_point(class_definition:google.protobuf.Value) */ {
 public:
  inline Value() : Value(nullptr) {}
  ~Value() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Value(
      ::google::protobuf::internal::ConstantInitialized);

  inline Value(const Value& from) : Value(nullptr, from) {}
  inline Value(Value&& from) noexcept
      : Value(nullptr, std::move(from)) {}
  inline Value& operator=(const Value& from) {
    CopyFrom(from);
    return *this;
  }
  inline Value& operator=(Value&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const std::string& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<std::string>(::google::protobuf::internal::GetEmptyString);
  }
  inline std::string* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<std::string>();
  }

  static const Value& default_instance() {
    return *internal_default_instance();
  }
  enum KindCase {
    kNullValue = 1,
    kNumberValue = 2,
    kStringValue = 3,
    kBoolValue = 4,
    kStructValue = 5,
    kListValue = 6,
    KIND_NOT_SET = 0,
  };
  static inline const Value* internal_default_instance() {
    return reinterpret_cast<const Value*>(
        &_Value_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 2;
  friend void swap(Value& a, Value& b) { a.Swap(&b); }
  inline void Swap(Value* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Value* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Value* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::MessageLite::DefaultConstruct<Value>(arena);
  }
  void CheckTypeAndMergeFrom(
      const ::google::protobuf::MessageLite& from) final;
  void CopyFrom(const Value& from);
  void MergeFrom(const Value& from);
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Value* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "google.protobuf.Value"; }

 protected:
  explicit Value(::google::protobuf::Arena* arena);
  Value(::google::protobuf::Arena* arena, const Value& from);
  Value(::google::protobuf::Arena* arena, Value&& from) noexcept
      : Value(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kNullValueFieldNumber = 1,
    kNumberValueFieldNumber = 2,
    kStringValueFieldNumber = 3,
    kBoolValueFieldNumber = 4,
    kStructValueFieldNumber = 5,
    kListValueFieldNumber = 6,
  };
  // .google.protobuf.NullValue null_value = 1;
  bool has_null_value() const;
  void clear_null_value() ;
  ::google::protobuf::NullValue null_value() const;
  void set_null_value(::google::protobuf::NullValue value);

  private:
  ::google::protobuf::NullValue _internal_null_value() const;
  void _internal_set_null_value(::google::protobuf::NullValue value);

  public:
  // double number_value = 2;
  bool has_number_value() const;
  void clear_number_value() ;
  double number_value() const;
  void set_number_value(double value);

  private:
  double _internal_number_value() const;
  void _internal_set_number_value(double value);

  public:
  // string string_value = 3;
  bool has_string_value() const;
  void clear_string_value() ;
  const std::string& string_value() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_string_value(Arg_&& arg, Args_... args);
  std::string* mutable_string_value();
  PROTOBUF_NODISCARD std::string* release_string_value();
  void set_allocated_string_value(std::string* value);

  private:
  const std::string& _internal_string_value() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_string_value(
      const std::string& value);
  std::string* _internal_mutable_string_value();

  public:
  // bool bool_value = 4;
  bool has_bool_value() const;
  void clear_bool_value() ;
  bool bool_value() const;
  void set_bool_value(bool value);

  private:
  bool _internal_bool_value() const;
  void _internal_set_bool_value(bool value);

  public:
  // .google.protobuf.Struct struct_value = 5;
  bool has_struct_value() const;
  private:
  bool _internal_has_struct_value() const;

  public:
  void clear_struct_value() ;
  const ::google::protobuf::Struct& struct_value() const;
  PROTOBUF_NODISCARD ::google::protobuf::Struct* release_struct_value();
  ::google::protobuf::Struct* mutable_struct_value();
  void set_allocated_struct_value(::google::protobuf::Struct* value);
  void unsafe_arena_set_allocated_struct_value(::google::protobuf::Struct* value);
  ::google::protobuf::Struct* unsafe_arena_release_struct_value();

  private:
  const ::google::protobuf::Struct& _internal_struct_value() const;
  ::google::protobuf::Struct* _internal_mutable_struct_value();

  public:
  // .google.protobuf.ListValue list_value = 6;
  bool has_list_value() const;
  private:
  bool _internal_has_list_value() const;

  public:
  void clear_list_value() ;
  const ::google::protobuf::ListValue& list_value() const;
  PROTOBUF_NODISCARD ::google::protobuf::ListValue* release_list_value();
  ::google::protobuf::ListValue* mutable_list_value();
  void set_allocated_list_value(::google::protobuf::ListValue* value);
  void unsafe_arena_set_allocated_list_value(::google::protobuf::ListValue* value);
  ::google::protobuf::ListValue* unsafe_arena_release_list_value();

  private:
  const ::google::protobuf::ListValue& _internal_list_value() const;
  ::google::protobuf::ListValue* _internal_mutable_list_value();

  public:
  void clear_kind();
  KindCase kind_case() const;
  // @@protoc_insertion_point(class_scope:google.protobuf.Value)
 private:
  class _Internal;
  void set_has_null_value();
  void set_has_number_value();
  void set_has_string_value();
  void set_has_bool_value();
  void set_has_struct_value();
  void set_has_list_value();
  inline bool has_kind() const;
  inline void clear_has_kind();
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 6, 2,
      42, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    union KindUnion {
      constexpr KindUnion() : _constinit_{} {}
      ::google::protobuf::internal::ConstantInitialized _constinit_;
      int null_value_;
      double number_value_;
      ::google::protobuf::internal::ArenaStringPtr string_value_;
      bool bool_value_;
      ::google::protobuf::Struct* struct_value_;
      ::google::protobuf::ListValue* list_value_;
    } kind_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::uint32_t _oneof_case_[1];
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_struct_5flite_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// Struct

// map<string, .google.protobuf.Value> fields = 1;
inline int Struct::_internal_fields_size() const {
  return _internal_fields().size();
}
inline int Struct::fields_size() const {
  return _internal_fields_size();
}
inline void Struct::clear_fields() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.fields_.Clear();
}
inline const ::google::protobuf::Map<std::string, ::google::protobuf::Value>& Struct::_internal_fields() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.fields_.GetMap();
}
inline const ::google::protobuf::Map<std::string, ::google::protobuf::Value>& Struct::fields() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_map:google.protobuf.Struct.fields)
  return _internal_fields();
}
inline ::google::protobuf::Map<std::string, ::google::protobuf::Value>* Struct::_internal_mutable_fields() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.fields_.MutableMap();
}
inline ::google::protobuf::Map<std::string, ::google::protobuf::Value>* Struct::mutable_fields() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_map:google.protobuf.Struct.fields)
  return _internal_mutable_fields();
}

// -------------------------------------------------------------------

// Value

// .google.protobuf.NullValue null_value = 1;
inline bool Value::has_null_value() const {
  return kind_case() == kNullValue;
}
inline void Value::set_has_null_value() {
  _impl_._oneof_case_[0] = kNullValue;
}
inline void Value::clear_null_value() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (kind_case() == kNullValue) {
    _impl_.kind_.null_value_ = 0;
    clear_has_kind();
  }
}
inline ::google::protobuf::NullValue Value::null_value() const {
  // @@protoc_insertion_point(field_get:google.protobuf.Value.null_value)
  return _internal_null_value();
}
inline void Value::set_null_value(::google::protobuf::NullValue value) {
  if (kind_case() != kNullValue) {
    clear_kind();
    set_has_null_value();
  }
  _impl_.kind_.null_value_ = value;
  // @@protoc_insertion_point(field_set:google.protobuf.Value.null_value)
}
inline ::google::protobuf::NullValue Value::_internal_null_value() const {
  if (kind_case() == kNullValue) {
    return static_cast<::google::protobuf::NullValue>(_impl_.kind_.null_value_);
  }
  return static_cast<::google::protobuf::NullValue>(0);
}

// double number_value = 2;
inline bool Value::has_number_value() const {
  return kind_case() == kNumberValue;
}
inline void Value::set_has_number_value() {
  _impl_._oneof_case_[0] = kNumberValue;
}
inline void Value::clear_number_value() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (kind_case() == kNumberValue) {
    _impl_.kind_.number_value_ = 0;
    clear_has_kind();
  }
}
inline double Value::number_value() const {
  // @@protoc_insertion_point(field_get:google.protobuf.Value.number_value)
  return _internal_number_value();
}
inline void Value::set_number_value(double value) {
  if (kind_case() != kNumberValue) {
    clear_kind();
    set_has_number_value();
  }
  _impl_.kind_.number_value_ = value;
  // @@protoc_insertion_point(field_set:google.protobuf.Value.number_value)
}
inline double Value::_internal_number_value() const {
  if (kind_case() == kNumberValue) {
    return _impl_.kind_.number_value_;
  }
  return 0;
}

// string string_value = 3;
inline bool Value::has_string_value() const {
  return kind_case() == kStringValue;
}
inline void Value::set_has_string_value() {
  _impl_._oneof_case_[0] = kStringValue;
}
inline void Value::clear_string_value() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (kind_case() == kStringValue) {
    _impl_.kind_.string_value_.Destroy();
    clear_has_kind();
  }
}
inline const std::string& Value::string_value() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:google.protobuf.Value.string_value)
  return _internal_string_value();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Value::set_string_value(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (kind_case() != kStringValue) {
    clear_kind();

    set_has_string_value();
    _impl_.kind_.string_value_.InitDefault();
  }
  _impl_.kind_.string_value_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:google.protobuf.Value.string_value)
}
inline std::string* Value::mutable_string_value() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_string_value();
  // @@protoc_insertion_point(field_mutable:google.protobuf.Value.string_value)
  return _s;
}
inline const std::string& Value::_internal_string_value() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  if (kind_case() != kStringValue) {
    return ::google::protobuf::internal::GetEmptyStringAlreadyInited();
  }
  return _impl_.kind_.string_value_.Get();
}
inline void Value::_internal_set_string_value(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (kind_case() != kStringValue) {
    clear_kind();

    set_has_string_value();
    _impl_.kind_.string_value_.InitDefault();
  }
  _impl_.kind_.string_value_.Set(value, GetArena());
}
inline std::string* Value::_internal_mutable_string_value() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (kind_case() != kStringValue) {
    clear_kind();

    set_has_string_value();
    _impl_.kind_.string_value_.InitDefault();
  }
  return _impl_.kind_.string_value_.Mutable( GetArena());
}
inline std::string* Value::release_string_value() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:google.protobuf.Value.string_value)
  if (kind_case() != kStringValue) {
    return nullptr;
  }
  clear_has_kind();
  return _impl_.kind_.string_value_.Release();
}
inline void Value::set_allocated_string_value(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (has_kind()) {
    clear_kind();
  }
  if (value != nullptr) {
    set_has_string_value();
    _impl_.kind_.string_value_.InitAllocated(value, GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.Value.string_value)
}

// bool bool_value = 4;
inline bool Value::has_bool_value() const {
  return kind_case() == kBoolValue;
}
inline void Value::set_has_bool_value() {
  _impl_._oneof_case_[0] = kBoolValue;
}
inline void Value::clear_bool_value() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (kind_case() == kBoolValue) {
    _impl_.kind_.bool_value_ = false;
    clear_has_kind();
  }
}
inline bool Value::bool_value() const {
  // @@protoc_insertion_point(field_get:google.protobuf.Value.bool_value)
  return _internal_bool_value();
}
inline void Value::set_bool_value(bool value) {
  if (kind_case() != kBoolValue) {
    clear_kind();
    set_has_bool_value();
  }
  _impl_.kind_.bool_value_ = value;
  // @@protoc_insertion_point(field_set:google.protobuf.Value.bool_value)
}
inline bool Value::_internal_bool_value() const {
  if (kind_case() == kBoolValue) {
    return _impl_.kind_.bool_value_;
  }
  return false;
}

// .google.protobuf.Struct struct_value = 5;
inline bool Value::has_struct_value() const {
  return kind_case() == kStructValue;
}
inline bool Value::_internal_has_struct_value() const {
  return kind_case() == kStructValue;
}
inline void Value::set_has_struct_value() {
  _impl_._oneof_case_[0] = kStructValue;
}
inline void Value::clear_struct_value() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (kind_case() == kStructValue) {
    if (GetArena() == nullptr) {
      delete _impl_.kind_.struct_value_;
    }
    clear_has_kind();
  }
}
inline ::google::protobuf::Struct* Value::release_struct_value() {
  // @@protoc_insertion_point(field_release:google.protobuf.Value.struct_value)
  if (kind_case() == kStructValue) {
    clear_has_kind();
    auto* temp = _impl_.kind_.struct_value_;
    if (GetArena() != nullptr) {
      temp = ::google::protobuf::internal::DuplicateIfNonNull(temp);
    }
    _impl_.kind_.struct_value_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::google::protobuf::Struct& Value::_internal_struct_value() const {
  return kind_case() == kStructValue ? *_impl_.kind_.struct_value_ : reinterpret_cast<::google::protobuf::Struct&>(::google::protobuf::_Struct_default_instance_);
}
inline const ::google::protobuf::Struct& Value::struct_value() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:google.protobuf.Value.struct_value)
  return _internal_struct_value();
}
inline ::google::protobuf::Struct* Value::unsafe_arena_release_struct_value() {
  // @@protoc_insertion_point(field_unsafe_arena_release:google.protobuf.Value.struct_value)
  if (kind_case() == kStructValue) {
    clear_has_kind();
    auto* temp = _impl_.kind_.struct_value_;
    _impl_.kind_.struct_value_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Value::unsafe_arena_set_allocated_struct_value(::google::protobuf::Struct* value) {
  // We rely on the oneof clear method to free the earlier contents
  // of this oneof. We can directly use the pointer we're given to
  // set the new value.
  clear_kind();
  if (value) {
    set_has_struct_value();
    _impl_.kind_.struct_value_ = value;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:google.protobuf.Value.struct_value)
}
inline ::google::protobuf::Struct* Value::_internal_mutable_struct_value() {
  if (kind_case() != kStructValue) {
    clear_kind();
    set_has_struct_value();
    _impl_.kind_.struct_value_ =
        ::google::protobuf::MessageLite::DefaultConstruct<::google::protobuf::Struct>(GetArena());
  }
  return _impl_.kind_.struct_value_;
}
inline ::google::protobuf::Struct* Value::mutable_struct_value() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::google::protobuf::Struct* _msg = _internal_mutable_struct_value();
  // @@protoc_insertion_point(field_mutable:google.protobuf.Value.struct_value)
  return _msg;
}

// .google.protobuf.ListValue list_value = 6;
inline bool Value::has_list_value() const {
  return kind_case() == kListValue;
}
inline bool Value::_internal_has_list_value() const {
  return kind_case() == kListValue;
}
inline void Value::set_has_list_value() {
  _impl_._oneof_case_[0] = kListValue;
}
inline void Value::clear_list_value() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (kind_case() == kListValue) {
    if (GetArena() == nullptr) {
      delete _impl_.kind_.list_value_;
    }
    clear_has_kind();
  }
}
inline ::google::protobuf::ListValue* Value::release_list_value() {
  // @@protoc_insertion_point(field_release:google.protobuf.Value.list_value)
  if (kind_case() == kListValue) {
    clear_has_kind();
    auto* temp = _impl_.kind_.list_value_;
    if (GetArena() != nullptr) {
      temp = ::google::protobuf::internal::DuplicateIfNonNull(temp);
    }
    _impl_.kind_.list_value_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::google::protobuf::ListValue& Value::_internal_list_value() const {
  return kind_case() == kListValue ? *_impl_.kind_.list_value_ : reinterpret_cast<::google::protobuf::ListValue&>(::google::protobuf::_ListValue_default_instance_);
}
inline const ::google::protobuf::ListValue& Value::list_value() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:google.protobuf.Value.list_value)
  return _internal_list_value();
}
inline ::google::protobuf::ListValue* Value::unsafe_arena_release_list_value() {
  // @@protoc_insertion_point(field_unsafe_arena_release:google.protobuf.Value.list_value)
  if (kind_case() == kListValue) {
    clear_has_kind();
    auto* temp = _impl_.kind_.list_value_;
    _impl_.kind_.list_value_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Value::unsafe_arena_set_allocated_list_value(::google::protobuf::ListValue* value) {
  // We rely on the oneof clear method to free the earlier contents
  // of this oneof. We can directly use the pointer we're given to
  // set the new value.
  clear_kind();
  if (value) {
    set_has_list_value();
    _impl_.kind_.list_value_ = value;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:google.protobuf.Value.list_value)
}
inline ::google::protobuf::ListValue* Value::_internal_mutable_list_value() {
  if (kind_case() != kListValue) {
    clear_kind();
    set_has_list_value();
    _impl_.kind_.list_value_ =
        ::google::protobuf::MessageLite::DefaultConstruct<::google::protobuf::ListValue>(GetArena());
  }
  return _impl_.kind_.list_value_;
}
inline ::google::protobuf::ListValue* Value::mutable_list_value() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::google::protobuf::ListValue* _msg = _internal_mutable_list_value();
  // @@protoc_insertion_point(field_mutable:google.protobuf.Value.list_value)
  return _msg;
}

inline bool Value::has_kind() const {
  return kind_case() != KIND_NOT_SET;
}
inline void Value::clear_has_kind() {
  _impl_._oneof_case_[0] = KIND_NOT_SET;
}
inline Value::KindCase Value::kind_case() const {
  return Value::KindCase(_impl_._oneof_case_[0]);
}
// -------------------------------------------------------------------

// ListValue

// repeated .google.protobuf.Value values = 1;
inline int ListValue::_internal_values_size() const {
  return _internal_values().size();
}
inline int ListValue::values_size() const {
  return _internal_values_size();
}
inline void ListValue::clear_values() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.values_.Clear();
}
inline ::google::protobuf::Value* ListValue::mutable_values(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:google.protobuf.ListValue.values)
  return _internal_mutable_values()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::google::protobuf::Value>* ListValue::mutable_values()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:google.protobuf.ListValue.values)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_values();
}
inline const ::google::protobuf::Value& ListValue::values(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:google.protobuf.ListValue.values)
  return _internal_values().Get(index);
}
inline ::google::protobuf::Value* ListValue::add_values() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::google::protobuf::Value* _add = _internal_mutable_values()->Add();
  // @@protoc_insertion_point(field_add:google.protobuf.ListValue.values)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::google::protobuf::Value>& ListValue::values() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:google.protobuf.ListValue.values)
  return _internal_values();
}
inline const ::google::protobuf::RepeatedPtrField<::google::protobuf::Value>&
ListValue::_internal_values() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.values_;
}
inline ::google::protobuf::RepeatedPtrField<::google::protobuf::Value>*
ListValue::_internal_mutable_values() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.values_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
}  // namespace google


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::google::protobuf::NullValue> : std::true_type {};

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_struct_5flite_2eproto_2epb_2eh
