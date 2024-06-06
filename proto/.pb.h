// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: .proto
// Protobuf C++ Version: 5.27.0

#ifndef GOOGLE_PROTOBUF_INCLUDED__2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED__2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5027000
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT__2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct__2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table__2eproto;
class Term;
struct TermDefaultTypeInternal;
extern TermDefaultTypeInternal _Term_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class Term final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:Term) */ {
 public:
  inline Term() : Term(nullptr) {}
  ~Term() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Term(
      ::google::protobuf::internal::ConstantInitialized);

  inline Term(const Term& from) : Term(nullptr, from) {}
  inline Term(Term&& from) noexcept
      : Term(nullptr, std::move(from)) {}
  inline Term& operator=(const Term& from) {
    CopyFrom(from);
    return *this;
  }
  inline Term& operator=(Term&& from) noexcept {
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

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Term& default_instance() {
    return *internal_default_instance();
  }
  static inline const Term* internal_default_instance() {
    return reinterpret_cast<const Term*>(
        &_Term_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Term& a, Term& b) { a.Swap(&b); }
  inline void Swap(Term* other) {
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
  void UnsafeArenaSwap(Term* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Term* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<Term>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Term& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Term& from) { Term::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Term* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "Term"; }

 protected:
  explicit Term(::google::protobuf::Arena* arena);
  Term(::google::protobuf::Arena* arena, const Term& from);
  Term(::google::protobuf::Arena* arena, Term&& from) noexcept
      : Term(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kTermFieldNumber = 1,
    kDidFieldNumber = 2,
  };
  // string term = 1;
  void clear_term() ;
  const std::string& term() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_term(Arg_&& arg, Args_... args);
  std::string* mutable_term();
  PROTOBUF_NODISCARD std::string* release_term();
  void set_allocated_term(std::string* value);

  private:
  const std::string& _internal_term() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_term(
      const std::string& value);
  std::string* _internal_mutable_term();

  public:
  // uint64 did = 2;
  void clear_did() ;
  ::uint64_t did() const;
  void set_did(::uint64_t value);

  private:
  ::uint64_t _internal_did() const;
  void _internal_set_did(::uint64_t value);

  public:
  // @@protoc_insertion_point(class_scope:Term)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      17, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_Term_default_instance_;

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
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const Term& from_msg);
    ::google::protobuf::internal::ArenaStringPtr term_;
    ::uint64_t did_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct__2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Term

// string term = 1;
inline void Term::clear_term() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.term_.ClearToEmpty();
}
inline const std::string& Term::term() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Term.term)
  return _internal_term();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Term::set_term(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.term_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:Term.term)
}
inline std::string* Term::mutable_term() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_term();
  // @@protoc_insertion_point(field_mutable:Term.term)
  return _s;
}
inline const std::string& Term::_internal_term() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.term_.Get();
}
inline void Term::_internal_set_term(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.term_.Set(value, GetArena());
}
inline std::string* Term::_internal_mutable_term() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.term_.Mutable( GetArena());
}
inline std::string* Term::release_term() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:Term.term)
  return _impl_.term_.Release();
}
inline void Term::set_allocated_term(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.term_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.term_.IsDefault()) {
          _impl_.term_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Term.term)
}

// uint64 did = 2;
inline void Term::clear_did() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.did_ = ::uint64_t{0u};
}
inline ::uint64_t Term::did() const {
  // @@protoc_insertion_point(field_get:Term.did)
  return _internal_did();
}
inline void Term::set_did(::uint64_t value) {
  _internal_set_did(value);
  // @@protoc_insertion_point(field_set:Term.did)
}
inline ::uint64_t Term::_internal_did() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.did_;
}
inline void Term::_internal_set_did(::uint64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.did_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED__2eproto_2epb_2eh
